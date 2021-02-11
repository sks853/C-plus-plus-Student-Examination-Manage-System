/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file manage_admin.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/23 22:31:42
 *
 * @version 1.0
 *
 * @description 封装了适合本工程的管理员界面菜单和处理
 *
 * **************************************************
 */

#ifndef MANAGE_ADMIN_H
#define MANAGE_ADMIN_H


/*-------------------- Import Lib --------------------*/

#include "main.h"


/*-------------------- User Functions --------------------*/

 /**
  * **************************************************
  *
  * @brief print menu of admin
  *
  * @param menus (menu&) self-define menu
  *
  * @retval None
  *
  * **************************************************
  */
void print_menu_admin(menu& menus);


 /**
  * **************************************************
  *
  * @brief print menu of create account
  *
  * @param menus (menu&) self-define menu
  *
  * @retval None
  *
  * **************************************************
  */
void print_menu_admin_account_create(menu& menus);


/**
 * **************************************************
 *
 * @brief print menu of delete account
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_account_delete();


/**
 * **************************************************
 *
 * @brief print menu of creating administrative class
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_create_class();


/**
 * **************************************************
 *
 * @brief print menu of deleting administrative class
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_delete_class();


/**
 * **************************************************
 *
 * @brief create a comprehensive examination
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_exam_create_comprehensive_examination();


/**
 * **************************************************
 *
 * @brief Single subject examination, including detailed examination conditions
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_exam_create_selective_examination();


/**
 * **************************************************
 *
 * @brief create an exam
 *
 * @param menus (menu&) menu
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_exam_create(menu& menus);


/**
 * **************************************************
 *
 * @brief alert student scores
 *
 * @param menus (menu&) menu
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_exam_update(menu& menus);

#endif
