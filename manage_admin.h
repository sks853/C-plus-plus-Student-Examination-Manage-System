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
 * @description ��װ���ʺϱ����̵Ĺ���Ա����˵��ʹ���
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
 * @brief create student information
 *
 * @param menus (const menu&) menus
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_student_create(const menu& menus);

/**
 * **************************************************
 *
 * @brief delete a student information
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_student_delete();

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
void print_menu_admin_score_update(menu& menus);

#endif
