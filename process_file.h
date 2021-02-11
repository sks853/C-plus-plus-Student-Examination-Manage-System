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
 * @description 封装了适合本工程的文件读写处理
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


// 宏定义：单次数据最大缓存
#define MAXSIZE_BUFF	1024

// 宏定义：日志文件路径
#define PATH_FILE_LOGS			"./data/config/log.log"

// 宏定义：配置文件路径
#define PATH_FILE_PROPERTIES    "./data/config/init.ini"

#define PATH_FOLDER_ACCOUNTS	"./data/info/account/"

#define PATH_FOLDER_CLASS		"./data/info/class/"

#define PATH_FOLDER_RECORD		"./data/record/"

// 宏定义：配置文件中[account]标志
#define SIGN_PROPERTIES_ACCOUNT	"[account]"

// 宏定义：配置文件中[class]标志
#define SIGN_PROPERTIES_CLASS	"[class]"

// 宏定义：配置文件中[record]标志
#define SIGN_PROPERTIES_RECORD	"[record]"


// 日志严重程度状态码
enum severity_code
{
	// 严重
	severity_code_error = 0,
	// 警告
	severity_code_warning = 1,
	// 提示
	severity_code_info = 2
};


// 全局：当前登陆用户的账号信息
extern std::vector<const char*> g_vector_login_info;

// 静态：日志文件指针
static std::ofstream g_ptr_log;

// 静态：存储用户信息的文件路径
static std::vector<std::string> g_vector_file_path_account;

// 静态：存储班级信息的文件路径
static std::vector<std::string> g_vector_file_path_class;

// 静态：存储考试信息的文件路径
static std::vector<std::string> g_vector_file_path_record;


/**
 * **************************************************
 *
 * @brief 登陆验证
 *
 * @param user_name (const char*) 参数：输入的用户名/账号
 *
 * @param user_password (const char*) 参数：输入的密码
 *
 * @return bool 返回：是否通过验证
 *
 * @retval true 结果：验证通过
 *
 * @retval false 结果：验证失败
 *
 * **************************************************
 */
bool user_verify(const char* user_name, const char* user_password);


/**
 * **************************************************
 *
 * @brief 查找一个用户信息并返回对应的存储结构
 *
 * @param user_name (const char*) 参数：待查找的用户名
 *
 * @return student_info* 返回：包含用户信息结构的类对象指针，查找的操作结果存储在flag_operation中
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
 * @brief 移除字符串尾部的格式字符
 *
 * @param str (string&) 参数：待判定的字符串
 *
 * @return string 返回：字符串
 *
 * **************************************************
 */
std::string trim(const std::string& str);


/**
 * **************************************************
 *
 * @brief 打印输出日志到日志文件（必须先初始化该日志的文件指针）
 *
 * @param logs (const char*) 参数：单条日志信息
 *
 * @param severity_code (const int) 参数：单条日志严重程度状态码, 代码从0->2 代表 [Error]->[Warning]->[Info], 默认=1
 *
 * @retval None
 *
 * **************************************************
 */
void print_log(const char* logs, const int severity_code = 1);

/**
 * **************************************************
 *
 * @brief 验证输入的文件路径是否合法
 *
 * @param file_path (const char*) 参数：文件路径
 *
 * @return bool 返回：表示合法或不合法
 *
 * @retval true 结果：合法
 *
 * @retval false 结果：非法
 *
 * **************************************************
 */
bool is_valid_file_path(const char* file_path);

/**
 * **************************************************
 *
 * @brief 读取配置文件，并存放在静态变量容器中
 *
 * @retval None
 *
 * **************************************************
 */
void init_properties();


/**
 * **************************************************
 *
 * @brief 初始化日志文件指针
 *
 * @retval None
 *
 * **************************************************
 */
void init_log();


#endif

