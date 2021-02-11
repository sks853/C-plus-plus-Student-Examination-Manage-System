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
	 * @brief Administrator界面
	 * 
	 * 0. Exit								退出
	 * 1. Create account					新建用户
	 * 2. Delete account					删除用户
	 * 3. Create administrative class		新建行政班级
	 * 4. Delete administrative class		删除行政班级
	 * 5. Create student information		新建学生信息
	 * 6. Delete student information		删除学生信息
	 * 7. Create New Exam					新建考试
	 * 8. Alter Exam Score					更新成绩
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_admin_main;


	/**
	 * **************************************************
	 *
	 * @brief 考试类型菜单
	 *
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
