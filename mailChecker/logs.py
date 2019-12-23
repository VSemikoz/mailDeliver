# -*- coding: utf-8 -*-
import logging

class Logs:
    def __init__(self, settings_dict):
        self.settings_dict = settings_dict
        self.logger = logging.getLogger("dbChecker")
        self.logger.setLevel(logging.INFO)
        self.fh = logging.FileHandler("logs.log")
        self.formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        self.fh.setFormatter(self.formatter)
        self.logger.addHandler(self.fh)

    def send_mail_mail_list_is_absent(self):
        send_mail_string = "NO MESSAGES FOUND FOR SENDING\n"
        return send_mail_string

    def send_mail_log_string(self, address, group, receiver, files):
        if self.settings_dict["LOG_FILE_ATTACHED_FILES_SEPARATOR"] != "NONE":
            attached_files_separator = self.settings_dict["LOG_FILE_ATTACHED_FILES_SEPARATOR"]
            if attached_files_separator == "\\n":
                files = '\n'.join(files.split(", "))
            else:
                files = attached_files_separator.join(files.split(", "))
        send_mail_string = "SEND FROM %s TO %s group receiver is %s\n" \
                           "ATTACHED FILES ARE: \n%s\n" \
                           % (address, group, receiver, files)
        return send_mail_string

    def error_send_mail_log_string(self, address, group, receiver, files):
        if self.settings_dict["LOG_FILE_ATTACHED_FILES_SEPARATOR"] != "NONE":
            attached_files_separator = self.settings_dict["LOG_FILE_ATTACHED_FILES_SEPARATOR"]
            if attached_files_separator == "\\n":
                files = '\n'.join(files.split(", "))
            else:
                files = attached_files_separator.join(files.split(", "))
        send_mail_string = "__ERROR__ SEND FROM %s TO %s group receiver is %s\n" \
                           "ATTACHED FILES ARE: \n%s\n" \
                           % (address, group, receiver, files)
        return send_mail_string

    def login_log_string(self, address):
        send_mail_string = "AUTHORIZED BY %s\n" \
                           % address
        return send_mail_string\

    def error_login_log_string(self, address):
        send_mail_string = "__FAILED__ AUTHORIZED BY %s\n" \
                           % address
        return send_mail_string

    def error_server_conn_log_string(self, server):
        send_mail_string = "__FAILED__ CONNECTION TO SERVER %s\n"\
                            % server
        return send_mail_string

    def server_conn_log_string(self, server):
        send_mail_string = "CONNECTION TO SERVER %s\n" \
                           % server
        return send_mail_string

    def create_info_log(self, log_string):
        self.logger.info(log_string)

    def create_error_log(self, log_string):
        self.logger.error(log_string)




