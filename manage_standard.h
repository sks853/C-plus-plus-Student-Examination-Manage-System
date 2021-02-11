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
 * @description ��װ���ʺϱ����̵ı�׼��д�û�����˵��ʹ���
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
 * @brief ��ӡ��׼�û����˵�ѡ��
 *
 * @param menus (menu&) �������˵������
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_standard_main(menu& menus);


/**
 * **************************************************
 *
 * @brief �����û���ѧ�š��༶����Ϣ
 *
 * @param menus (menu&) �������˵������
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_standard_mange_student(menu& menus);


/**
 * **************************************************
 *
 * @brief ����ѧ�����Գɼ�
 *
 * @param menus (menu&) �������˵������
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_standard_mange_exam(menu& menus);

#endif
