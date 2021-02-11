/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file manage_standard.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/27 00:45:45
 *
 * @version 1.0
 *
 * @description 封装了适合本工程的标准读写用户界面菜单和处理
 *
 * **************************************************
 */

#ifndef	MANAGE_STANDARD_H
#define MANAGE_STANDARD_H

 /*-------------------- Import Lib --------------------*/

#include "main.h"


/*-------------------- User Functions --------------------*/

/**
 * **************************************************
 *
 * @brief 打印标准用户主菜单选项
 *
 * @param menus (menu&) 参数：菜单类对象
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_standard_main(menu& menus);


/**
 * **************************************************
 *
 * @brief 管理用户的学号、班级等信息
 *
 * @param menus (menu&) 参数：菜单类对象
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_standard_mange_student(menu& menus);


/**
 * **************************************************
 *
 * @brief 管理学生考试成绩
 *
 * @param menus (menu&) 参数：菜单类对象
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_standard_mange_exam(menu& menus);

#endif
