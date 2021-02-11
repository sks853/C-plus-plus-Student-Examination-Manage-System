# -*- coding:utf-8 -*-
# ===============================================
# @Author       HDM
# @Copyright    HDM
# @blogs        https://blog.csdn.net/qq_43634664
# @Version      0.0.1
# @Time         2021/2/9 15:41
# @FileName     generate_exam.py
# @Description  None
# ===============================================

import csv
import string
import random

AMOUNT_EXAM = 20


class generate_exam:
    def __init__(self, folder_path, student_info):
        self.folder_path = folder_path
        self.student_info = student_info
        self.datetime = ""
        self.admin = "root"
        self.count_student = len(student_info)
        self.count_major = random.randint(2, 10)
        self.average = 0.0
        self.major = []
        self.major_score = []
        self.ls_record = []
        self.path = []

    def store_exam(self):
        for index in range(AMOUNT_EXAM):
            self.create_exam()
            file_path = self.folder_path + r"/exam_" + str(index) + r".csv"
            base = (self.datetime, self.admin, self.count_student, self.average, self.count_major)
            ls = [base, self.major, self.major_score]
            for ele in self.ls_record:
                ls.append(ele)
            with open(file_path, "w", encoding="gb2312", newline='') as f:
                writer = csv.writer(f, delimiter=",")
                for i in ls:
                    writer.writerow(i)
            self.path.append(file_path)
            self.clean_exam()

    def clean_exam(self):
        self.datetime = ""
        self.count_major = random.randint(2, 10)
        self.average = 0.0
        self.major.clear()
        self.major_score.clear()
        self.ls_record.clear()

    def create_exam(self):
        self.create_exam_datetime()
        self.create_exam_major_serial_num()
        self.create_exam_student_record()
        self.statistics_exam()

    def print_exam(self):
        base = [self.datetime, self.admin, self.count_student, self.average, self.count_major]
        print(base)
        print(self.major)
        print(self.major_score)
        for ele in self.ls_record:
            print(ele)

    def statistics_exam(self):
        self.average = round(self.average / self.count_student, 1)
        for index in range(self.count_major):
            self.major_score[index] = round(self.major_score[index] / self.count_student, 1)

    def create_exam_student_record(self):
        for i in range(self.count_student):
            rank = 0
            student_name = self.student_info[i][3]
            student_class = self.student_info[i][5]
            student_id = self.student_info[i][4]
            student_score_major = []
            for index in range(self.count_major):
                major_score = round(random.uniform(45, 95), 1)
                student_score_major.append(major_score)
                if 0 == i:
                    self.major_score.append(major_score)
                else:
                    self.major_score[index] += major_score
            student_score_average = round(sum(student_score_major) / self.count_major, 1)
            self.average += student_score_average
            student = [rank, student_name, student_class, student_id, student_score_average]
            for element in student_score_major:
                student.append(element)
            self.ls_record.append(student)
        self.ls_record = sorted(self.ls_record, key=lambda x: x[4], reverse=True)
        for index in range(self.count_student):
            self.ls_record[index][0] = index + 1

    def create_exam_major_serial_num(self):
        for i in range(self.count_major):
            major = ""
            for index in range(5):
                major += random.choice(string.ascii_letters + string.digits)
            self.major.append(major)

    def create_exam_datetime(self):
        datetime = ""
        datetime += str(random.randint(2018, 2024))
        month = random.randint(1, 12)
        if month < 10:
            datetime += '0' + str(month)
        else:
            datetime += str(month)
        day = random.randint(1, 31)
        if month < 10:
            datetime += "0" + str(day)
        else:
            datetime += str(day)
        hour = random.randint(1, 23)
        if hour < 10:
            datetime += "0" + str(hour)
        else:
            datetime += str(hour)
        minute = random.randint(1, 59)
        if minute < 10:
            datetime += "0" + str(minute)
        else:
            datetime += str(minute)
        self.datetime = datetime
