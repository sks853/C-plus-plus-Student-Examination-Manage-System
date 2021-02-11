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
 * @description ��װ���ʺϱ����̵Ĳ˵�����
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
	 * @brief ѡ���Ա�˵�
	 * 
	 * 0. female							Ů
	 * 1. male								��
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_menu_select_gender;

	/*---------------------------------------- Menus ----------------------------------------*/

	/**
	 * **************************************************
	 *
	 * @brief ֻ���û������¸�����Ϣ����ĵ�ǰ�û���Ϣ�����ʽ
	 *
	 * 1. User Name: 						�û���
	 * 2. User Password: 					����
	 * 3. Privilege: 						Ȩ��
	 * 4. Name: 							����
	 * 5. ID: 								ѧ��
	 * 6. Class ID: 						�����༶��
	 * 7. Gender: 							�Ա�
	 * 
	 * **************************************************
	 */
	std::vector<const char*> vector_read_info_manage_tip;

	
	/**
	 * **************************************************
	 *
	 * @brief ֻ���û������¸�����Ϣ�����޸ĸ�����Ϣѡ��
	 *
	 * 0. Back								����
	 * 1. Alter User Name					�޸��û���
	 * 2. Alter User Password				�޸�����
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_read_info_manage_alter;


	/**
	 * **************************************************
	 *
	 * @brief ֻ���û�������ͳ�ƿ�������˵�
	 *
	 * 0. Back								����
	 * 1. Statistics All Examination					ͳ��ȫ�����Գɼ�
	 * 2. Statistics Examination According Datetime		ͳ��ָ�����ڷ�Χ�������
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_read_exam_statistics;

	
	/**
	 * **************************************************
	 *
	 * @brief ֻ���û��Ľ���˵�
	 *
	 * 0. Exit								�˳�
	 * 1. Personal Information Manage		������Ϣ����
	 * 2. Statistics Examination			ͳ�ƿ������
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_read_main;
	
	
	/**
	 * **************************************************
	 *
	 * @brief Administrator����˵�
	 * 
	 * 0. Exit								�˳�
	 * 1. Create account					�½��û�
	 * 2. Delete account					ɾ���û�
	 * 3. Create administrative class		�½������༶
	 * 4. Delete administrative class		ɾ�������༶
	 * 5. Create New Exam					�½�����
	 * 6. Alter Exam Score					���³ɼ�
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_admin_main;


	/**
	 * **************************************************
	 *
	 * @brief �������Ͳ˵�
	 *
	 * 0. Back								����
	 * 1. Comprehensive Examination			�ۺ��Կ���
	 * 2. Selective Examination				ѡ���Կ���
	 *
	 * **************************************************
	 */
	std::vector<const char*> vector_menu_exam_type;


	/**
	 * **************************************************
	 *
	 * @brief ��Ŀѡ��˵�
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
	 * @brief Administrator�����µĴ����˻����棬ѡ���û�Ȩ�޲˵�
	 * 
	 * 0. Back								����
	 * 1. Standard Account					��׼�û�
	 * 2. Only-Read Account					ֻ���û�
	 * 
	 * **************************************************
	 */
	std::vector<const char*> vector_menu_create_account;

};


#endif
