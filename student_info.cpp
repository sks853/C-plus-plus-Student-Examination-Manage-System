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
 * @brief  打印不为空的成员变量
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
 * @brief 设置创建用户信息必需参数
 *
 * @param get_user_id (char*) 账号
 *
 * @param get_user_password (char*) 密码
 *
 * @param get_user_privilege (int) 权限
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
 * @brief 设置创建学生信息必需参数
 *
 * @param get_user_id (char*) 账号
 *
 * @param get_student_name (char*) 姓名
 *
 * @param get_student_id (char*) 学号
 *
 * @param get_student_class (char*) 班级号
 *
 * @param get_gender (const int) 性别
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
