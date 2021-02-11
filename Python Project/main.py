# -*- coding:utf-8 -*-
# ===============================================
# @Author       HDM
# @Copyright    HDM
# @blogs        https://blog.csdn.net/qq_43634664
# @Version      0.0.1
# @Time         2021/2/9 14:26
# @FileName     main.py
# @Description  None
# ===============================================

from generate_user_info import generate_user
from generate_exam import generate_exam

K_PATH_FOLDER_DATA = r"C:/Users/THDMI/source/repos/sks853/C-plus-plus-Student-Examination-Manage-System/NoUi_Student_Manage_System/data"

k_PATH_FOLDER_CONFIG = K_PATH_FOLDER_DATA + r"/config"
K_PATH_FOLDER_INFO_ACCOUNT = K_PATH_FOLDER_DATA + r"/info/account"
K_PATH_FOLDER_INFO_CLASS = K_PATH_FOLDER_DATA + r"/info/class"
K_PATH_FOLDER_INFO_RECORD = K_PATH_FOLDER_DATA + r"/record"

K_PATH_FILE_PROPERTIES = k_PATH_FOLDER_CONFIG + r"/init.ini"
K_PATH_FILE_LOG = k_PATH_FOLDER_CONFIG + r"/log.log"

g_ls_path_file_account = []
g_ls_path_file_class = []
g_ls_path_file_record = []


def init_properties():
    with open(K_PATH_FILE_PROPERTIES, "r+", encoding='GB2312') as f:
        ls_properties = []
        flag_properties = 0
        for line in f:
            ls = line.split()
            for ele in ls:
                ls_properties.append(ele.replace(r"./data", K_PATH_FOLDER_DATA))
        for ele in ls_properties:
            if "[account]" == ele:
                flag_properties = 1
                continue
            if "[class]" == ele:
                flag_properties = 2
                continue
            if "[record]" == ele:
                flag_properties = 3
                continue
            if 1 == flag_properties:
                g_ls_path_file_account.append(ele)
            elif 2 == flag_properties:
                g_ls_path_file_class.append(ele)
            elif 3 == flag_properties:
                g_ls_path_file_record.append(ele)


def append_account():
    global g_ls_path_file_account
    global g_ls_path_file_class
    global g_ls_path_file_record
    for index in range(len(g_ls_path_file_account)):
        g_ls_path_file_account[index] = g_ls_path_file_account[index].replace(K_PATH_FOLDER_DATA, r"./data")
    for index in range(len(g_ls_path_file_class)):
        g_ls_path_file_class[index] = g_ls_path_file_class[index].replace(K_PATH_FOLDER_DATA, r"./data")
    for index in range(len(g_ls_path_file_record)):
        g_ls_path_file_record[index] = g_ls_path_file_record[index].replace(K_PATH_FOLDER_DATA, r"./data")

    with open(K_PATH_FILE_PROPERTIES, "w+", encoding="gb2312", newline='') as f:
        f.write("[account]\n")
        for ele_account in g_ls_path_file_account:
            f.write(ele_account + "\n")
        f.write("[class]\n")
        for ele_class in g_ls_path_file_class:
            f.write(ele_class + "\n")
        f.write("[record]\n")
        for ele_record in g_ls_path_file_record:
            f.write(ele_record + "\n")


if __name__ == '__main__':
    """ main """
    init_properties()
    user_info = generate_user(K_PATH_FOLDER_INFO_ACCOUNT + r"/account_1.csv")
    exam = generate_exam(K_PATH_FOLDER_INFO_RECORD, user_info.generate_account())
    exam.store_exam()
    for element in exam.path:
        g_ls_path_file_record.append(element)
    append_account()
