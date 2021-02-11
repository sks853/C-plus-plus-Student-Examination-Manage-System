/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file menu.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/23 18:22:30
 *
 * @version 1.0
 *
 * @description 封装了适合本工程的菜单内容
 *
 * **************************************************
 */

#ifndef MENU_H
#define MENU_H


/*-------------------- Import Standard Lib --------------------*/

#include <vector>


/*-------------------- User class --------------------*/

class menu
{
public:

	
	/*-------------------- User Functions --------------------*/
	
	/**
	 * **************************************************
	 *
	 * @brief init class of menu
	 *
	 * @retval None
	 *
	 * **************************************************
	 */
	menu();


	/*-------------------- User Values --------------------*/

	/*---------------------------------------- Others ----------------------------------------*/

	/**
	 * **************************************************
	 *
	 * @brief 选择性别菜单
	 * 
	 * 0. female							女
	 * 1. male								男
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_menu_select_gender;

	/*---------------------------------------- Menus ----------------------------------------*/

	/**
	 * **************************************************
	 *
	 * @brief 只读用户界面下个人信息管理的当前用户信息输出格式
	 *
	 * 1. User Name: 						用户名
	 * 2. User Password: 					密码
	 * 3. Privilege: 						权限
	 * 4. Name: 							姓名
	 * 5. ID: 								学号
	 * 6. Class ID: 						行政班级号
	 * 7. Gender: 							性别
	 * 
	 * **************************************************
	 */
	std::vector<const char*> vector_read_info_manage_tip;

	
	/**
	 * **************************************************
	 *
	 * @brief 只读用户界面下个人信息管理修改个人信息选项
	 *
	 * 0. Back								返回
	 * 1. Alter User Name					修改用户名
	 * 2. Alter User Password				修改密码
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_read_info_manage_alter;


	/**
	 * **************************************************
	 *
	 * @brief 只读用户界面下统计考试情况菜单
	 *
	 * 0. Back								返回
	 * 1. Statistics All Examination					统计全部考试成绩
	 * 2. Statistics Examination According Datetime		统计指定日期范围考试情况
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_read_exam_statistics;

	
	/**
	 * **************************************************
	 *
	 * @brief 只读用户的界面菜单
	 *
	 * 0. Exit								退出
	 * 1. Personal Information Manage		个人信息管理
	 * 2. Statistics Examination			统计考试情况
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_read_main;
	
	
	/**
	 * **************************************************
	 *
	 * @brief Administrator界面菜单
	 * 
	 * 0. Exit								退出
	 * 1. Create account					新建用户
	 * 2. Delete account					删除用户
	 * 3. Create administrative class		新建行政班级
	 * 4. Delete administrative class		删除行政班级
	 * 5. Create New Exam					新建考试
	 * 6. Alter Exam Score					更新成绩
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_admin_main;


	/**
	 * **************************************************
	 *
	 * @brief 考试类型菜单
	 *
	 * 0. Back								返回
	 * 1. Comprehensive Examination			综合性考试
	 * 2. Selective Examination				选择性考试
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_menu_exam_type;


	/**
	 * **************************************************
	 *
	 * @brief 科目选择菜单
	 *
	 * 1. Subject 1
	 * 2. Subject 2
	 * 3. Subject 3
	 * 4. Subject 4
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_menu_exam_course;
	

	/**
	 * **************************************************
	 *
	 * @brief Administrator界面下的创建账户界面，选择用户权限菜单
	 * 
	 * 0. Back								返回
	 * 1. Standard Account					标准用户
	 * 2. Only-Read Account					只读用户
	 * 
	 * **************************************************
	 */
	std::vector<const char*> vector_menu_create_account;

};


#endif
