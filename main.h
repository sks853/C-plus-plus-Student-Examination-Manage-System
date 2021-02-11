/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file main.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/23 10:23:00
 *
 * @version 1.0
 *
 * @description ����������������ʺϱ����̵ķ�װ
 *
 * **************************************************
 */

#ifndef MAIN_H
#define MAIN_H


 /*-------------------- Import Standard Lib --------------------*/

#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <fstream>


/*-------------------- Import User Lib --------------------*/

#include "menu.h"
#include "format_input.h"
#include "format_print.h"
#include "process_file.h"

#include "manage_admin.h"
#include "manage_standard.h"
#include "manage_read.h"

#include "student_info.h"
#include "class_info.h"
#include "exam_info.h"
#include "exam_record_info.h"

#include "template_free_pointer.h"
#include "template_operation_info.h"


/*-------------------- User Macro Definition --------------------*/

// ��������
#define CLEAN					system("cls")


/*-------------------- User/External Values --------------------*/


/*-------------------- User Enum --------------------*/

// �û�����Ȩ��
enum operation_privilege
{
	privilege_admin = 0,		// ����ԱȨ��
	privilege_standard = 1,		// ��׼��дȨ��
	privilege_read = 2			// ��׼�鿴Ȩ��
};


/*-------------------- User Functions --------------------*/

/**
 * **************************************************
 *
 * @brief �ж�������ַ����ǲ��Ǵ��������ͣ������ÿ⺯�������
 *
 * @param str (const char*) ������������ַ���
 *
 * @return bool ���أ�������ַ����ǲ��Ǵ�����
 *
 * @retval true ������Ǵ�����
 *
 * @retval false ��������Ǵ�����
 *
 * **************************************************
 */
bool is_positive_integer(const char* str);


/**
 * **************************************************
 *
 * @brief ��ӡ��½���棬����õ�½�û�Ȩ��
 *
 * @return (int) ��½�û���Ȩ��
 *
 * **************************************************
 */
int login_verify();

#endif
