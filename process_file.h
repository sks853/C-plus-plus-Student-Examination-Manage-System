/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file process_file.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/28 14:20:58
 *
 * @version 1.0
 *
 * @description ��װ���ʺϱ����̵��ļ���д����
 *
 * **************************************************
 */

#ifndef PROCESS_FILE_H
#define PROCESS_FILE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include <time.h>
#include <direct.h>
#include <io.h>

#include "template_free_pointer.h"
#include "student_information.h"


// �궨�壺����������󻺴�
#define MAXSIZE_BUFF	1024

// �궨�壺��־�ļ�·��
#define PATH_FILE_LOGS			"./data/config/log.log"

// �궨�壺�����ļ�·��
#define PATH_FILE_PROPERTIES    "./data/config/init.ini"

#define PATH_FOLDER_ACCOUNTS	"./data/info/account/"

#define PATH_FOLDER_CLASS		"./data/info/class/"

#define PATH_FOLDER_RECORD		"./data/record/"

// �궨�壺�����ļ���[account]��־
#define SIGN_PROPERTIES_ACCOUNT	"[account]"

// �궨�壺�����ļ���[class]��־
#define SIGN_PROPERTIES_CLASS	"[class]"

// �궨�壺�����ļ���[record]��־
#define SIGN_PROPERTIES_RECORD	"[record]"


// ��־���س̶�״̬��
enum severity_code
{
	// ����
	severity_code_error = 0,
	// ����
	severity_code_warning = 1,
	// ��ʾ
	severity_code_info = 2
};


// ȫ�֣���ǰ��½�û����˺���Ϣ
extern std::vector<const char*> g_vector_login_info;

// ��̬����־�ļ�ָ��
static std::ofstream g_ptr_log;

// ��̬���洢�û���Ϣ���ļ�·��
static std::vector<std::string> g_vector_file_path_account;

// ��̬���洢�༶��Ϣ���ļ�·��
static std::vector<std::string> g_vector_file_path_class;

// ��̬���洢������Ϣ���ļ�·��
static std::vector<std::string> g_vector_file_path_record;


/**
 * **************************************************
 *
 * @brief ��½��֤
 *
 * @param user_name (const char*) ������������û���/�˺�
 *
 * @param user_password (const char*) ���������������
 *
 * @return bool ���أ��Ƿ�ͨ����֤
 *
 * @retval true �������֤ͨ��
 *
 * @retval false �������֤ʧ��
 *
 * **************************************************
 */
bool user_verify(const char* user_name, const char* user_password);


/**
 * **************************************************
 *
 * @brief ����һ���û���Ϣ�����ض�Ӧ�Ĵ洢�ṹ
 *
 * @param user_name (const char*) �����������ҵ��û���
 *
 * @return student_info* ���أ������û���Ϣ�ṹ�������ָ�룬���ҵĲ�������洢��flag_operation��
 *
 * **************************************************
 */
student_info* user_select(const char* user_name);


/**
 * **************************************************
 *
 * @brief
 *
 * @param student (const student_info&)
 *
 * @return
 *
 * @retval
 *
 * @retval
 *
 * **************************************************
 */
bool user_store(const student_info* student);


/**
 * **************************************************
 *
 * @brief �Ƴ��ַ���β���ĸ�ʽ�ַ�
 *
 * @param str (string&) ���������ж����ַ���
 *
 * @return string ���أ��ַ���
 *
 * **************************************************
 */
std::string trim(const std::string& str);


/**
 * **************************************************
 *
 * @brief ��ӡ�����־����־�ļ��������ȳ�ʼ������־���ļ�ָ�룩
 *
 * @param logs (const char*) ������������־��Ϣ
 *
 * @param severity_code (const int) ������������־���س̶�״̬��, �����0->2 ���� [Error]->[Warning]->[Info], Ĭ��=1
 *
 * @retval None
 *
 * **************************************************
 */
void print_log(const char* logs, const int severity_code = 1);

/**
 * **************************************************
 *
 * @brief ��֤������ļ�·���Ƿ�Ϸ�
 *
 * @param file_path (const char*) �������ļ�·��
 *
 * @return bool ���أ���ʾ�Ϸ��򲻺Ϸ�
 *
 * @retval true ������Ϸ�
 *
 * @retval false ������Ƿ�
 *
 * **************************************************
 */
bool is_valid_file_path(const char* file_path);

/**
 * **************************************************
 *
 * @brief ��ȡ�����ļ���������ھ�̬����������
 *
 * @retval None
 *
 * **************************************************
 */
void init_properties();


/**
 * **************************************************
 *
 * @brief ��ʼ����־�ļ�ָ��
 *
 * @retval None
 *
 * **************************************************
 */
void init_log();


#endif

