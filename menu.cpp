/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file menu.cpp
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/23 18:22:30
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "menu.h"

 /*---------------------------------------- Menus ----------------------------------------*/

/**
 * **************************************************
 *
 * @brief Administrator����
 *
 * @details login >> admin >> Create account
 *
 * **************************************************
 */
const char* menu_admin_main[] = {
		"0. Exit",							// �˳�
		"1. Create Account",				// �½��û�
		"2. Delete Account",				// ɾ���û�
		"3. Create Administrative Class",	// �½������༶
		"4. Delete Administrative Class",	// ɾ�������༶
		"5. Create New Exam",				// �½�����
		"6. Alter Exam Score"				// ���³ɼ�
};


/**
 * **************************************************
 *
 * @brief Administrator�����µĴ����˻����棬ѡ���û�Ȩ�޲˵�
 *
 * @details login >> admin
 *
 * **************************************************
 */
const char* menu_create_account[] = {
		"0. Back",							// ����
		"1. Standard Account",				// ��׼�û�
		"2. Only-Read Account"				// ֻ���û�
};


/**
 * **************************************************
 * 
 * @brief �������Ͳ˵�
 * 
 * **************************************************
 */
const char* menu_exam_type[] = {
	"0. Back",								// ����
	"1. Comprehensive Examination",			// �ۺ��Կ���
	"2. Selective Examination"				// ѡ���Կ���
};


/**
 * **************************************************
 *
 * @brief ��Ŀѡ��˵�
 *
 * **************************************************
 */
const char* menu_exam_course[] = {
	"1. Subject 1",
	"2. Subject 2",
	"3. Subject 3",
	"4. Subject 4"
};


/*---------------------------------------- Others ----------------------------------------*/

/**
 * **************************************************
 *
 * @brief ѡ���Ա�˵�
 *
 * **************************************************
 */
const char* menu_select_gender[] = {
		"0. female",						// Ů
		"1. male"							// ��
};


/**
 * **************************************************
 *
 * @brief init class of menu
 *
 * @retval None
 *
 * **************************************************
 */
menu::menu()
{
	/*---------------------------------------- Menus ----------------------------------------*/
	
	// login >> admin
	for (const char* ele : menu_admin_main)
	{
		vector_admin_main.push_back(ele);
	}

	// login >> admin >> Create account
	for (const char* ele : menu_create_account)
	{
		vector_menu_create_account.push_back(ele);
	}

	// login >> admin >> Create student information
	for (const char* ele :menu_select_gender)
	{
		vector_menu_select_gender.push_back(ele);
	}

	for (const char* ele : menu_exam_type)
	{
		vector_menu_exam_type.push_back(ele);
	}

	for (const char* ele : menu_exam_course)
	{
		vector_menu_exam_course.push_back(ele);
	}
}

