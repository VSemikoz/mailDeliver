# -*- coding: utf-8 -*-
def open_settings_file():
    f = open('..//Settings.txt', 'r')
    return f

def get_settings_dict():
    f = open_settings_file()
    setting_dict = {}
    for setting_string in f.read().split("\n"):
        setting_string_list = setting_string.split(' ')
        if setting_string_list[0] and setting_string_list[1]:
            setting_dict[setting_string_list[0]] = setting_string_list[1]
    return setting_dict

