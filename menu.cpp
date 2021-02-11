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
 * @brief Only-Read �û�����
 *
 * @details login >> read-only
 *
 * **************************************************
 */
const char* menu_read_main[] = {
		"0. Exit",							// �˳�
		"1. Personal Information Manage",	// ������Ϣ����
		"2. Statistics Examination"			// ͳ�ƿ������
};


/**
 * **************************************************
 *
 * @brief Only-Read �µĲ鿴������ϢĬ�ϳ���
 *
 * @details login >> read-only >> Personal Information Manage
 *
 * **************************************************
 */
const char* menu_read_info_manage_tip[] = {
		"User Name: ",						// �û���
		"User Password: ",					// ����
		"Privilege: ",						// Ȩ��
		"Name: ",							// ����
		"ID: ",								// ѧ��
		"Class ID: ",						// �����༶��
		"Gender: "							// �Ա�
};


/**
 * **************************************************
 *
 * @brief Only-Read ��ѡ���޸ĵĸ�����Ϣ
 *
 * @details login >> read-only >> Personal Information Manage
 *
 * **************************************************
 */
const char* menu_read_info_manage_alter[] = {
		"0. Back",							// ����
		"1. Alter User Name",				// �û���
		"2. Alter User Password",			// ����
};


/**
 * **************************************************
 *
 * @brief Only-Read �²�ѯ��ǰ�˺��µ�ȫ���򲿷ֳɼ�
 *
 * @details login >> read-only >> Statistics Examination
 *
 * **************************************************
 */
const char* menu_read_exam_statistics[] = {
		"0. Back",
		"1. Statistics All Examination",
		"2. Statistics Examination According Datetime",
};


/**
 * **************************************************
 *
 * @brief Administrator����
 *
 * @details login >> admin
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
 * @brief ��Ŀѡ��˵��������ڵ��ƿ��ԣ�
 *
 * **************************************************
 */
const char* menu_exam_course[] = {
	"1. Subject 1",							// ��Ŀһ
	"2. Subject 2",							// ��Ŀ��
	"3. Subject 3",							// ��Ŀ��
	"4. Subject 4"							// ��Ŀ��
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

	// login >> only_read
	for (const char* ele : menu_read_main)
	{
		vector_read_main.push_back(ele);
	}

	// login >> only_read >> Personal Information Manage
	for (const char* ele : menu_read_info_manage_tip)
	{
		vector_read_info_manage_tip.push_back(ele);
	}

	// login >> only_read >> Personal Information Manage
	for (const char* ele : menu_read_info_manage_alter)
	{
		vector_read_info_manage_alter.push_back(ele);
	}

	// login >> only_read >> Examination According
	for (const char* ele : menu_read_exam_statistics)
	{
		vector_read_exam_statistics.push_back(ele);
	}
	
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

