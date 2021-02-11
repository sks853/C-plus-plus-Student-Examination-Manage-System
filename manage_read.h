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
  * @brief ��ӡֻ���û�����Ĳ����˵�
  *
  * @param menus (menu&) �������˵������
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
 * @brief ��ӡ������Ϣ���ѡ��˵�������һ������
 *
 * @param menus (menu&) �������˵������
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_personal_information_manage(menu& menus);


/**
 * **************************************************
 *
 * @brief ��ӡͳ�ƿ�����Ϣ�Ĳ˵������д���
 *
 * @param menus (menu&) �������˵������
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_read_statistics_examination(menu& menus);



#endif
