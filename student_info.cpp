/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file student_information.cpp
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/25 12:15:20
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "student_info.h"


/**
 * **************************************************
 *
 * @brief  ��ӡ��Ϊ�յĳ�Ա����
 *
 * @retval None
 *
 * **************************************************
 */
void student_info::print_information()
{
	if (user_id != nullptr)
	{
		std::cout << "User Id: " << user_id << std::endl;
	}
	if (user_password != nullptr)
	{
		std::cout << "User Password: " << "************" << std::endl;
	}
	if (user_privilege != -1)
	{
		std::cout << "User Privilege: " << (1 == user_privilege ? "Standard" : "Read-Only") << std::endl;
	}
	if (name != nullptr)
	{
		std::cout << "User True Name: " << name << std::endl;
	}
	if (id != nullptr)
	{
		std::cout << "Study Id: " << id << std::endl;
	}
	if (class_id != nullptr)
	{
		std::cout << "Class Id: " << class_id << std::endl;
	}
	if (-1 != gender)
	{
		std::cout << "Gender: " << (1 == gender ? "Male" : "Female") << std::endl;
	}
}

/**
 * **************************************************
 *
 * @brief ���ô����û���Ϣ�������
 *
 * @param get_user_id (char*) �˺�
 *
 * @param get_user_password (char*) ����
 *
 * @param get_user_privilege (int) Ȩ��
 *
 * @retval None
 *
 * **************************************************
 */
void student_info::set_student_account(const int get_user_privilege, char* get_user_password, char* get_user_id)
{
	user_id = get_user_id;
	user_password = get_user_password;
	user_privilege = get_user_privilege;
}

/**
 * **************************************************
 *
 * @brief ���ô���ѧ����Ϣ�������
 *
 * @param get_user_id (char*) �˺�
 *
 * @param get_student_name (char*) ����
 *
 * @param get_student_id (char*) ѧ��
 *
 * @param get_student_class (char*) �༶��
 *
 * @param get_gender (const int) �Ա�
 *
 * @retval None
 *
 * **************************************************
 */
void student_info::set_student_info(const int get_gender, char* get_student_class, char* get_student_id, char* get_student_name, char* get_user_id)
{
	user_id = get_user_id;
	name = get_student_name;
	id = get_student_id;
	class_id = get_student_class;
	gender = get_gender;
}
