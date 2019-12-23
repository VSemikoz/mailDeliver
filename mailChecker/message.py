# -*- coding: utf-8 -*-
class Message:
    def __init__(self, message):
        self.id = message[0]
        self.group_name = message[1]
        self.recipient = message[2]
        self.header = message[3]
        self.body = message[4]
        self.date = message[5]
        self.time = message[6]
        self.file_name = message[7]


