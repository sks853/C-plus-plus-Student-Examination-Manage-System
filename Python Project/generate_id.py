# -*- coding:utf-8 -*-
# ===============================================
# @Author       HDM
# @Copyright    HDM
# @blogs        https://blog.csdn.net/qq_43634664
# @Version      0.0.1
# @Time         2021/2/9 14:03
# @FileName     generate_id.py
# @Description  None
# ===============================================

import string
import random


def generate_uuid(length):
    uuid = ""
    for i in range(length):
        uuid += random.choice(string.ascii_letters + string.digits)
    return uuid


def generate_class_id(length):
    class_id = ""
    for i in range(length):
        class_id += random.choice(string.digits)
    return class_id


def generate_student_id(class_id):
    student_id = ""

    student_id += str(random.randint(2018, 2024))

    academy = random.randint(1, 12)
    if academy < 10:
        student_id += '0' + str(academy)
    else:
        student_id += str(academy)

    major = random.randint(1, 125)
    if major < 10:
        student_id += '00' + str(major)
    elif major < 100:
        student_id += '0' + str(major)
    else:
        student_id += str(major)

    student_id += class_id[-2:]

    last_id = random.randint(1, 75)
    if last_id < 10:
        student_id += '0' + str(last_id)
    else:
        student_id += str(last_id)

    return student_id
