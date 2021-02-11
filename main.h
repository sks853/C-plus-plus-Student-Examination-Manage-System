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
 * @description 包含主函数和相关适合本工程的封装
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
#include "manage_admin.h"
#include "student_information.h"
#include "template_free_pointer.h"
#include "format_input.h"
#include "format_print.h"
#include "process_file.h"


/*-------------------- User Macro Definition --------------------*/

// 快速清屏
#define CLEAN							system("cls")


/*-------------------- User/External Values --------------------*/


/*-------------------- User Enum --------------------*/

// 用户操作权限
enum operation_privilege
{
	privilege_admin = 0,		// 管理员权限
	privilege_standard = 1,		// 标准读写权限
	privilege_read = 2			// 标准查看权限
};


/*-------------------- User Functions --------------------*/

/**
 * **************************************************
 *
 * @brief 判断输入的字符串是不是纯数字类型（可以用库函数替代）
 *
 * @param str (const char*) 参数：输入的字符串
 *
 * @return bool 返回：输入的字符串是不是纯数字
 *
 * @retval true 结果：是纯数字
 *
 * @retval false 结果：不是纯数字
 *
 * **************************************************
 */
bool is_positive_integer(const char* str);


/**
 * **************************************************
 *
 * @brief 打印登陆界面，并获得登陆用户权限
 *
 * @return (int) 登陆用户的权限
 *
 * **************************************************
 */
int login_verify();

#endif
