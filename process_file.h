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
#include "template_operation_info.h"
#include "student_info.h"
#include "class_info.h"
#include "exam_info.h"

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
 * @param uuid (const char*) �����������ҵ��û�������ѧ�ţ�����Ψһ��ʶ����
 *
 * @param mode (const int) ��������ָ����������ģʽ��1�����û������ң�2����ѧ�Ų��ң�Ĭ��=1
 *
 * @return operation_info<student_info>* ���أ������û���Ϣ�ṹ�������ģ��ָ�룬���ҵĲ�������洢�ڳ�Ա����info_flag��
 *
 * **************************************************
 */
operation_info<student_info>* user_select(const char* uuid, int mode = 1);


/**
 * **************************************************
 *
 * @brief �����û���Ϣ���ֶ�
 *
 * @param key_mode (const int) �������ؼ��ֲ���ģʽ�����û�������=1����ѧ�Ų���=2
 *
 * @param key (const char*) �������ؼ���
 *
 * @param update_mode (const int) ������������ģʽ����0��6�ֱ��Ӧ�洢�˻���Ϣ���7���ֶ�
 *
 * @param update_value (const char*) ���������º������
 *
 * @return Status Code (int) ���أ�״̬��
 *
 * @retval 1 ��������²����ɹ�
 *
 * @retval 0 ������޷����ݹؼ����ҵ�����
 *
 * @retval -1 ������޸���������ֵʱ�����˺��з��������͵��ַ�
 *
 * @retval -2 ����������ģʽ��ֵδ֪
 *
 * @retval -3 ������ļ���ȡʱ�����쳣
 *
 * @retval -4 ������ļ��洢ʱ�����쳣
 *
 * @retval -5 ����������������Ѿ����ڻ򲻴��ڵ����޷�д��
 *
 * **************************************************
 */
int user_update(int key_mode, const char* key, int update_mode, const char* update_value);


/**
 * **************************************************
 *
 * @brief �洢�û���Ϣ
 *
 * @param student (const student_info*) ������ָ��ѧ��������ָ��
 *
 * @return bool ���أ��洢�ɹ����
 *
 * @retval true �����д��ɹ�
 *
 * @retval false �����д��ʧ��
 *
 * **************************************************
 */
bool user_store(const student_info* student);

/**
 * **************************************************
 *
 * @brief ����·���洢�û���Ϣ
 *
 * @param vector_account (student_info) ������ָ��ѧ������������
 *
 * @param path (const char*) �洢·��
 *
 * @return bool ���أ��洢�ɹ����
 *
 * @retval true �����д��ɹ�
 *
 * @retval false �����д��ʧ��
 *
 * **************************************************
 */
bool user_store(std::vector<student_info>& vector_account, const char* path);

/**
 * **************************************************
 *
 * @brief ����û���Ϣ������ɾ��
 *
 * @param operation (operation_info<student_info>*) ������������������
 *
 * @return operation_info<student_info>* ���أ��������������
 *
 * **************************************************
 */
operation_info<student_info>* user_delete(operation_info<student_info>* operation);


/**
 * **************************************************
 *
 * @brief ���Ұ༶��Ϣ�����ز��������
 *
 * @param class_id (const char*) ����������������༶��
 *
 * @return operation_info<class_info>* ���أ�ָ�����������ָ��
 *
 * **************************************************
 */
operation_info<class_info>* class_select(const char* class_id);


/**
 * **************************************************
 *
 * @brief �洢�༶��Ϣ
 *
 * @param classes (const class_info*) �������༶������ָ��
 *
 * @return bool ���أ��洢���
 * 
 * @retval true ���������ɹ�
 *
 * @retval false ���������ʧ��
 *
 * **************************************************
 */
bool class_store(const class_info* classes);


/**
 * **************************************************
 *
 * @brief ɾ��ָ�������༶��Ϣ
 *
 * @param operation (operation_info<class_info>*) �������༶����Ĳ��������ָ��
 *
 * @return operation_info<class_info>* ���أ��༶����Ĳ��������ָ�룬����ɹ���operation->info_flag=true
 *
 * **************************************************
 */
operation_info<class_info>* class_delete(operation_info<class_info>* operation);


/**
 * **************************************************
 *
 * @brief ����ȫ���Ŀ��Լ�¼���߰�ָ�����ڲ���
 *
 * @param student_id (const char*) ������ѧ��ѧ�ţ���Ϊ�գ�Ĭ��=nullptr
 *
 * @param datetime_start (const char*) ��������ʼ���ڣ���Ϊ�գ�Ĭ��=nullptr
 *
 * @param datetime_end (const char*) ��������ֹ���ڣ���Ϊ�գ�Ĭ��=nullptr
 *
 * @return operation_info<std::vector<std::vector<std::vector<char*>>>>* ���أ�����ָ���Լ�¼ָ�������
 *
 * **************************************************
 */
operation_info<exam_info*>* exam_select(const char* student_id = nullptr, char* datetime_start = nullptr, char* datetime_end = nullptr);


/**
 * **************************************************
 *
 * @brief ���³ɼ�
 *
 * @param operation ���������������
 *
 * @param student_id ������ѧ��
 *
 * @param subject_name ���������޸Ŀ�Ŀ��
 *
 * @param new_score �������³ɼ�
 *
 * @return operation_info<exam_info*>* ���أ����������
 *
 * **************************************************
 */
operation_info<exam_info*>* exam_update(operation_info<exam_info*>* operation, char* student_id, char* subject_name, double new_score);


/**
 * **************************************************
 *
 * @brief �洢���Լ�¼
 *
 * @param info (const exam_info*) ���������Լ�¼�����ָ��
 *
 * @param path (char*) �����������Ϊ�գ���洢���õ�ַ
 *
 * @return bool ���أ��洢���
 *
 * @retval true ���������ɹ�
 *
 * @retval false ���������ʧ��
 *
 * **************************************************
 */
bool exam_store(const exam_info* info, char* path = nullptr);


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
 * @param creator (const char*) ��������־��¼������
 *
 * @retval None
 *
 * **************************************************
 */
void print_log(const char* logs, int severity_code = 1, const char* creator = nullptr);

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


/**
 * **************************************************
 *
 * @brief ׷�������ļ���¼
 *
 * @param mode (const int) ģʽ=1:׷���˻��ļ�·��, mode=2:׷�Ӱ༶�ļ�·��, mode=3:׷�ӳɼ���¼�ļ�·��
 *
 * @param path (const char*) �Ϸ�·����������׺����
 *
 * @return bool ׷�Ӹ��½��
 *
 * @retval true ׷�ӳɹ�
 *
 * @retval false ׷��ʧ��
 *
 * **************************************************
 */
bool properties_update(const int mode, const char* path);

#endif

