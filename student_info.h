/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file student_information.h
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

#ifndef STUDENT_INFORMATION_H
#define STUDENT_INFORMATION_H

#include <iostream>


 // 用户名/ID最大长度
#define MAXSIZE_INPUT_USER_ID			6

// 密码最大长度
#define MAXSIZE_INPUT_USER_PASSWORD		12

// 姓名最大长度
#define MAXSIZE_STUDENT_NAME			4

// 学号最大长度
#define MAXSIZE_STUDENT_ID				13


/**
 * **************************************************
 *
 * @brief 类对象：学生信息
 *
 * **************************************************
 */
class student_info
{
public:

	/**
	 * **************************************************
	 *
	 * @brief  打印不为空的成员变量
	 *
	 * @retval None
	 *
	 * **************************************************
	 */
	void print_information();

	/**
	 * **************************************************
	 *
	 * @brief 设置创建学生账号必需参数
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
	void set_student_account(const int get_user_privilege, char* get_user_password, char* get_user_id);

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
	void set_student_info(int get_gender, char* get_student_class, char* get_student_id, char* get_student_name, char* get_user_id);


	/**
	 * **************************************************
	 * 
	 * @brief 账号（默认=nullptr）
	 *
	 * @details length: MAXSIZE_INPUT_USER_ID
	 *
	 * **************************************************
	 */
	char* user_id = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief 密码（默认=nullptr）
	 *
	 * @details length: MAXSIZE_INPUT_USER_PASSWORD
	 * 
	 * **************************************************
	 */
	char* user_password = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief 权限（默认=-1）
	 *
	 * @details 0: 超级用户, 1: 标准用户, 2: 只读用户
	 * 
	 * **************************************************
	 */
	int user_privilege = -1;

	/**
	 * **************************************************
	 *
	 * @brief 姓名（默认=nullptr）
	 *
	 * @details length: 12
	 *
	 * **************************************************
	 */
	char* name = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief 学号（默认=nullptr）
	 *
	 * @details length: 12
	 *
	 * **************************************************
	 */
	char* id = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief 班级（默认=nullptr）
	 *
	 * @details length: MAXSIZE_INPUT_CLASS_ID
	 * 
	 * **************************************************
	 */
	char* class_id = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief 性别（默认=-1）
	 *
	 * @details 1: 男, 0: 女
	 *
	 * **************************************************
	 */
	int gender = -1;
};

#endif
