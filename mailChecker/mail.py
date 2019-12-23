# -*- coding: utf-8 -*-
import smtplib
import email
import email.mime.application
import mimetypes
from email import encoders
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.mime.image import MIMEImage
from email.mime.audio import MIMEAudio
import os


class Mail:
    def __init__(self, settings_dict):
        self.address = settings_dict["EMAIL"]
        self.password = settings_dict["PASSWORD"]
        self.browse_type = settings_dict["BROWSE_TYPE"]

        self.mail_list = []

    def attach_file(self, msg, filepath):
        filename = os.path.basename(filepath)
        ctype, encoding = mimetypes.guess_type(filepath)
        if ctype is None or encoding is not None:
            ctype = 'application/octet-stream'
        maintype, subtype = ctype.split('/', 1)
        if maintype == 'text':
            with open(filepath) as fp:
                file = MIMEText(fp.read(), _subtype=subtype)
                fp.close()
        elif maintype == 'image':
            with open(filepath, 'rb') as fp:
                file = MIMEImage(fp.read(), _subtype=subtype)
                fp.close()
        elif maintype == 'audio':
            with open(filepath, 'rb') as fp:
                file = MIMEAudio(fp.read(), _subtype=subtype)
                fp.close()
        else:
            with open(filepath, 'rb') as fp:
                file = MIMEBase(maintype, subtype)
                file.set_payload(fp.read())
                fp.close()
                encoders.encode_base64(file)
        file.add_header('Content-Disposition', 'attachment', filename=filename)
        msg.attach(file)

    def get_file_list_browse_type_file(self, message):
        attach_file_list = []
        for file_path in message.file_name.split(', '):
            if os.path.isfile(file_path):
                attach_file_list.append(file_path)
        return attach_file_list

    def get_file_list_browse_type_directory(self, message):
        attach_file_list = []
        for directory in message.file_name.split(", "):
            for obj in os.listdir(directory):
                full_path = directory + '/' + obj
                if os.path.isfile(full_path):
                    attach_file_list.append(full_path)
        return attach_file_list

    def create_attach_file_list(self, message):
        attach_file_list = []
        if message.file_name == "":
            return
        if self.browse_type == "DIRECTORY":
            attach_file_list = self.get_file_list_browse_type_directory(message)
        if self.browse_type == "FILE":
            attach_file_list = self.get_file_list_browse_type_file(message)

        return attach_file_list

    def create_msg(self, message):
        msg = email.mime.Multipart.MIMEMultipart()
        msg['Subject'] = message.header
        msg['From'] = self.address
        msg['To'] = message.recipient
        msg['Group'] = message.group_name

        body = email.mime.Text.MIMEText(message.body.encode("utf8"))
        msg.attach(body)
        attach_file_list = self.create_attach_file_list(message)

        if message.file_name:
            msg['Attached_files'] = ', '.join(attach_file_list)
            for attach_file in attach_file_list:
                self.attach_file(msg, attach_file)
        else:
            msg['Attached_files'] = "ABSENT"

        self.mail_list.append(msg)

    def send_mails(self, log, settings_dict):
        # Connection to SMTP Server
        try:
            s = smtplib.SMTP(settings_dict['SMTP_SERVER'])
            s.starttls()
            log.create_info_log(log.server_conn_log_string(settings_dict["SMTP_SERVER"]))
        except:
            log.create_error_log(log.error_server_conn_log_string(settings_dict["SMTP_SERVER"]))
            return

        # Login to email service
        try:
            s.login(self.address, self.password)
            log.create_info_log(log.login_log_string(settings_dict["EMAIL"]))
        except:
            log.create_error_log(log.error_login_log_string(settings_dict["EMAIL"]))
            return

        # Send mails
        if not self.mail_list:
            log.create_info_log(log.send_mail_mail_list_is_absent())
            return

        for mail in self.mail_list:
            try:
                s.sendmail(self.address, [mail['To']], mail.as_string())
                print "SEND FROM %s TO %s group reciver is %s\n" \
                  " attached files are %s" \
                  % (self.address, mail['Group'], mail['TO'],  mail['Attached_files'])
                log.create_info_log(log.send_mail_log_string(self.address, mail['Group'], mail['TO'],  mail['Attached_files']))
            except:
                print "ERROR SEND FROM %s TO %s group\n" \
                      " attached files are %s" \
                      % (self.address, mail['Group'],  mail['Attached_files'])
                log.create_error_log(log.send_mail_log_string(self.address, mail['Group'], mail['TO'],  mail['Attached_files']))
                return

        s.quit()
