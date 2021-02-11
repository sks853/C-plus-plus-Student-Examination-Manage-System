/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file manage_read.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/02/05 22:01:10
 *
 * @version 1.0
 *
 * **************************************************
 */

#ifndef MANAGE_READ_H
#define MANAGE_READ_H

#include "main.h"


 /**
  * **************************************************
  *
  * @brief 打印只读用户界面的操作菜单
  *
  * @param menus (menu&) 参数：菜单类对象
  *
  * @retval None
  *
  * **************************************************
  */
void print_menu_read_main(menu& menus);

/**
/**
 * **************************************************
 *
 * @brief 打印个人信息相关选项菜单并做进一步处理
 *
 * @param menus (menu&) 参数：菜单类对象
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_personal_information_manage(menu& menus);


/**
 * **************************************************
 *
 * @brief 打印统计考试信息的菜单并进行处理
 *
 * @param menus (menu&) 参数：菜单类对象
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_read_statistics_examination(menu& menus);



#endif
