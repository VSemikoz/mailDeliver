#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
import sqlite3
import datetime
from message import Message
from mail import Mail
from settings import get_settings_dict
from logs import Logs
import sys

reload(sys)
sys.setdefaultencoding('utf-8')
DAYS_OF_WEEK_DICT = {u"Понедельник": 0, u"Вторник": 1, u"Среда": 2, u"Четверг": 3,
                     u"Пятница": 4, u"Суббота": 5, u"Воскресенье": 6}



class DB_Checker:
    def __init__(self):
        self.settings_dict = get_settings_dict()
        self.log = Logs(self.settings_dict)
        self.db_conn = sqlite3.connect(self.settings_dict["DATABASE_LOCATION"])
        self.cursor = self.db_conn.cursor()
        self.mail_connection = None
        self.new_day = False

        self.delta = int(self.settings_dict["TIME_DELTA"])

        self.curr_time = datetime.datetime.now()
        self.day_of_week = self.curr_time.weekday()

        self.curr_date_format = self.curr_time.strftime("%Y-%m-%d")
        self.curr_time_format = self.curr_time.strftime("%H:%M:")

        self.curr_top_time_format = None
        self.curr_bot_time_format = None

        self.select_query = "SELECT * FROM mail_table"
        self.delete_query = "Delete FROM mail_table WHERE ID=?"

        self.setup()

    def loggin(self):
        self.mail_connection = Mail(self.settings_dict)

    def setup(self):
        top_layer = self.curr_time + datetime.timedelta(minutes=self.delta)
        bot_layer = self.curr_time

        self.curr_top_time_format = top_layer.strftime("%H:%M:")
        self.curr_bot_time_format = bot_layer.strftime("%H:%M:")

        if self.curr_top_time_format < self.curr_bot_time_format:
            self.new_day = True

    def exec_select_query(self):
        self.cursor.execute(self.select_query)
        return self.cursor.fetchall()

    def get_message_list(self, query_result):
        mail_list = []
        for message in query_result:

            if ((not self.new_day) and self.curr_bot_time_format < message[6] < self.curr_top_time_format) or \
                    (self.new_day and (self.curr_bot_time_format < message[6] or message[6] < self.curr_top_time_format)):
                if message[5] in DAYS_OF_WEEK_DICT.keys() and DAYS_OF_WEEK_DICT[message[5]] == self.day_of_week or \
                        message[5] == self.curr_date_format:

                    for recipient in message[2].split(','):
                        recipient = recipient.replace(" ", "")
                        mes = [message[0], message[1], recipient, message[3], message[4], message[5], message[6],
                               message[7]]
                        mail_list.append(Message(mes))
        return mail_list

    def create_messages(self, message_list):
        for message in message_list:
            self.mail_connection.create_msg(message)
            if self.settings_dict["DELETE_AFTER_SENDING"] == "YES":
                self.cursor.execute(self.delete_query, [message.id])

    def commit_and_exit(self):
        self.db_conn.commit()
        self.db_conn.close()

    def send_mails(self):
        self.mail_connection.send_mails(self.log, self.settings_dict)


checker = DB_Checker()

checker.loggin()
query_result = checker.exec_select_query()
message_list = checker.get_message_list(query_result)

checker.create_messages(message_list)
checker.send_mails()
checker.commit_and_exit()
