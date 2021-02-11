# -*- coding:utf-8 -*-
# ===============================================
# @Author       HDM
# @Copyright    HDM
# @blogs        https://blog.csdn.net/qq_43634664
# @Version      0.0.1
# @Time         2021/2/9 14:26
# @FileName     generate_user_info.py
# @Description  None
# ===============================================

import csv
import random

from generate_chinese_names import generate_name
from generate_id import generate_uuid
from generate_id import generate_student_id
from generate_id import generate_class_id


class generate_user:
    def __init__(self, path):
        self.path = path

    def generate_account(self):
        ls = []
        tmp_ls = []
        for i in range(1000):
            user_name = generate_uuid(4)
            user_password = generate_uuid(6)
            privilege = random.choice(('1', '2'))
            student_gender = random.choice(('0', '1'))
            student_name = generate_name(gender=eval(student_gender))
            student_class = generate_class_id(6)
            student_id = generate_student_id(student_class)
            tmp_ls.append(
                (user_name, user_password, privilege, student_name, student_id, student_class, student_gender))
        tmp_ls_name = []
        tmp_ls_id = []
        count = 0
        for ele in tmp_ls:
            if not ele[0] in tmp_ls_name and not ele[4] in tmp_ls_id:
                count += 1
                ls.append(ele)
                tmp_ls_name.append(ele[0])
                tmp_ls_id.append(ele[4])
        ls = sorted(ls, key=lambda x: x[4])

        for i in ls:
            print(i)
        print("成功生成数据个数：", count)

        try:
            with open(self.path, "w", encoding='GB2312', newline='') as f:
                writer = csv.writer(f, delimiter=",")
                for i in ls:
                    writer.writerow(i)
        except Exception as e:
            print(e)

        return ls
