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
 * @brief Only-Read 用户界面
 *
 * @details login >> read-only
 *
 * **************************************************
 */
const char* menu_read_main[] = {
		"0. Exit",							// 退出
		"1. Personal Information Manage",	// 个人信息管理
		"2. Statistics Examination"			// 统计考试情况
};


/**
 * **************************************************
 *
 * @brief Only-Read 下的查看个人信息默认出现
 *
 * @details login >> read-only >> Personal Information Manage
 *
 * **************************************************
 */
const char* menu_read_info_manage_tip[] = {
		"User Name: ",						// 用户名
		"User Password: ",					// 密码
		"Privilege: ",						// 权限
		"Name: ",							// 姓名
		"ID: ",								// 学号
		"Class ID: ",						// 行政班级号
		"Gender: "							// 性别
};


/**
 * **************************************************
 *
 * @brief Only-Read 下选择修改的个人信息
 *
 * @details login >> read-only >> Personal Information Manage
 *
 * **************************************************
 */
const char* menu_read_info_manage_alter[] = {
		"0. Back",							// 返回
		"1. Alter User Name",				// 用户名
		"2. Alter User Password",			// 密码
};


/**
 * **************************************************
 *
 * @brief Only-Read 下查询当前账号下的全部或部分成绩
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
 * @brief Administrator界面
 *
 * @details login >> admin
 *
 * **************************************************
 */
const char* menu_admin_main[] = {
		"0. Exit",							// 退出
		"1. Create Account",				// 新建用户
		"2. Delete Account",				// 删除用户
		"3. Create Administrative Class",	// 新建行政班级
		"4. Delete Administrative Class",	// 删除行政班级
		"5. Create New Exam",				// 新建考试
		"6. Alter Exam Score"				// 更新成绩
};


/**
 * **************************************************
 *
 * @brief Administrator界面下的创建账户界面，选择用户权限菜单
 *
 * @details login >> admin
 *
 * **************************************************
 */
const char* menu_create_account[] = {
		"0. Back",							// 返回
		"1. Standard Account",				// 标准用户
		"2. Only-Read Account"				// 只读用户
};


/**
 * **************************************************
 * 
 * @brief 考试类型菜单
 * 
 * **************************************************
 */
const char* menu_exam_type[] = {
	"0. Back",								// 返回
	"1. Comprehensive Examination",			// 综合性考试
	"2. Selective Examination"				// 选择性考试
};


/**
 * **************************************************
 *
 * @brief 科目选择菜单（可用于单科考试）
 *
 * **************************************************
 */
const char* menu_exam_course[] = {
	"1. Subject 1",							// 科目一
	"2. Subject 2",							// 科目二
	"3. Subject 3",							// 科目三
	"4. Subject 4"							// 科目四
};


/*---------------------------------------- Others ----------------------------------------*/

/**
 * **************************************************
 *
 * @brief 选择性别菜单
 *
 * **************************************************
 */
const char* menu_select_gender[] = {
		"0. female",						// 女
		"1. male"							// 男
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

