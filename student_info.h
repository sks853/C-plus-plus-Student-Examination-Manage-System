/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file student_information.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/25 12:15:20
 *
 * @version 1.0
 *
 * **************************************************
 */

#ifndef STUDENT_INFORMATION_H
#define STUDENT_INFORMATION_H

#include <iostream>


 // �û���/ID��󳤶�
#define MAXSIZE_INPUT_USER_ID			6

// ������󳤶�
#define MAXSIZE_INPUT_USER_PASSWORD		12

// ������󳤶�
#define MAXSIZE_STUDENT_NAME			4

// ѧ����󳤶�
#define MAXSIZE_STUDENT_ID				13


/**
 * **************************************************
 *
 * @brief �����ѧ����Ϣ
 *
 * **************************************************
 */
class student_info
{
public:

	/**
	 * **************************************************
	 *
	 * @brief  ��ӡ��Ϊ�յĳ�Ա����
	 *
	 * @retval None
	 *
	 * **************************************************
	 */
	void print_information();

	/**
	 * **************************************************
	 *
	 * @brief ���ô���ѧ���˺ű������
	 *
	 * @param get_user_id (char*) �˺�
	 *
	 * @param get_user_password (char*) ����
	 *
	 * @param get_user_privilege (int) Ȩ��
	 *
	 * @retval None
	 *
	 * **************************************************
	 */
	void set_student_account(const int get_user_privilege, char* get_user_password, char* get_user_id);

	/**
	 * **************************************************
	 *
	 * @brief ���ô���ѧ����Ϣ�������
	 *
	 * @param get_user_id (char*) �˺�
	 *
	 * @param get_student_name (char*) ����
	 *
	 * @param get_student_id (char*) ѧ��
	 *
	 * @param get_student_class (char*) �༶��
	 *
	 * @param get_gender (const int) �Ա�
	 *
	 * @retval None
	 *
	 * **************************************************
	 */
	void set_student_info(int get_gender, char* get_student_class, char* get_student_id, char* get_student_name, char* get_user_id);


	/**
	 * **************************************************
	 * 
	 * @brief �˺ţ�Ĭ��=nullptr��
	 *
	 * @details length: MAXSIZE_INPUT_USER_ID
	 *
	 * **************************************************
	 */
	char* user_id = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief ���루Ĭ��=nullptr��
	 *
	 * @details length: MAXSIZE_INPUT_USER_PASSWORD
	 * 
	 * **************************************************
	 */
	char* user_password = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief Ȩ�ޣ�Ĭ��=-1��
	 *
	 * @details 0: �����û�, 1: ��׼�û�, 2: ֻ���û�
	 * 
	 * **************************************************
	 */
	int user_privilege = -1;

	/**
	 * **************************************************
	 *
	 * @brief ������Ĭ��=nullptr��
	 *
	 * @details length: 12
	 *
	 * **************************************************
	 */
	char* name = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief ѧ�ţ�Ĭ��=nullptr��
	 *
	 * @details length: 12
	 *
	 * **************************************************
	 */
	char* id = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief �༶��Ĭ��=nullptr��
	 *
	 * @details length: MAXSIZE_INPUT_CLASS_ID
	 * 
	 * **************************************************
	 */
	char* class_id = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief �Ա�Ĭ��=-1��
	 *
	 * @details 1: ��, 0: Ů
	 *
	 * **************************************************
	 */
	int gender = -1;
};

#endif
