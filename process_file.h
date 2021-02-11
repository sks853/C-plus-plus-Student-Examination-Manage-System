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
#include "template_operation_info.h"
#include "student_info.h"
#include "class_info.h"
#include "exam_info.h"

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
 * @param uuid (const char*) 参数：待查找的用户名，或学号（都是唯一标识符）
 *
 * @param mode (const int) 参数：按指定参数查找模式，1：按用户名查找，2：按学号查找，默认=1
 *
 * @return operation_info<student_info>* 返回：包含用户信息结构的类对象模板指针，查找的操作结果存储在成员变量info_flag中
 *
 * **************************************************
 */
operation_info<student_info>* user_select(const char* uuid, int mode = 1);


/**
 * **************************************************
 *
 * @brief 更新用户信息表字段
 *
 * @param key_mode (const int) 参数：关键字查找模式，按用户名查找=1，按学号查找=2
 *
 * @param key (const char*) 参数：关键字
 *
 * @param update_mode (const int) 参数：待更新模式，从0—6分别对应存储账户信息表的7个字段
 *
 * @param update_value (const char*) 参数：更新后的内容
 *
 * @return Status Code (int) 返回：状态码
 *
 * @retval 1 结果：更新操作成功
 *
 * @retval 0 结果：无法根据关键字找到数据
 *
 * @retval -1 结果：修改数字类数值时传入了含有非数字类型的字符
 *
 * @retval -2 结果：传入的模式数值未知
 *
 * @retval -3 结果：文件读取时出现异常
 *
 * @retval -4 结果：文件存储时出现异常
 *
 * @retval -5 结果：检测更新内容已经存在或不存在导致无法写入
 *
 * **************************************************
 */
int user_update(int key_mode, const char* key, int update_mode, const char* update_value);


/**
 * **************************************************
 *
 * @brief 存储用户信息
 *
 * @param student (const student_info*) 参数：指向学生类对象的指针
 *
 * @return bool 返回：存储成功与否
 *
 * @retval true 结果：写入成功
 *
 * @retval false 结果：写入失败
 *
 * **************************************************
 */
bool user_store(const student_info* student);

/**
 * **************************************************
 *
 * @brief 根据路径存储用户信息
 *
 * @param vector_account (student_info) 参数：指向学生类对象的容器
 *
 * @param path (const char*) 存储路径
 *
 * @return bool 返回：存储成功与否
 *
 * @retval true 结果：写入成功
 *
 * @retval false 结果：写入失败
 *
 * **************************************************
 */
bool user_store(std::vector<student_info>& vector_account, const char* path);

/**
 * **************************************************
 *
 * @brief 如果用户信息存在则删除
 *
 * @param operation (operation_info<student_info>*) 参数：传入操作类对象
 *
 * @return operation_info<student_info>* 返回：传出操作类对象
 *
 * **************************************************
 */
operation_info<student_info>* user_delete(operation_info<student_info>* operation);


/**
 * **************************************************
 *
 * @brief 查找班级信息并返回操作类对象
 *
 * @param class_id (const char*) 参数：输入的行政班级号
 *
 * @return operation_info<class_info>* 返回：指向操作类对象的指针
 *
 * **************************************************
 */
operation_info<class_info>* class_select(const char* class_id);


/**
 * **************************************************
 *
 * @brief 存储班级信息
 *
 * @param classes (const class_info*) 参数：班级类对象的指针
 *
 * @return bool 返回：存储结果
 * 
 * @retval true 结果：保存成功
 *
 * @retval false 结果：保存失败
 *
 * **************************************************
 */
bool class_store(const class_info* classes);


/**
 * **************************************************
 *
 * @brief 删除指定行政班级信息
 *
 * @param operation (operation_info<class_info>*) 参数：班级对象的操作类对象指针
 *
 * @return operation_info<class_info>* 返回：班级对象的操作类对象指针，如果成功则operation->info_flag=true
 *
 * **************************************************
 */
operation_info<class_info>* class_delete(operation_info<class_info>* operation);


/**
 * **************************************************
 *
 * @brief 查找全部的考试记录或者按指定日期查找
 *
 * @param student_id (const char*) 参数：学生学号，可为空，默认=nullptr
 *
 * @param datetime_start (const char*) 参数：起始日期，可为空，默认=nullptr
 *
 * @param datetime_end (const char*) 参数：截止日期，可为空，默认=nullptr
 *
 * @return operation_info<std::vector<std::vector<std::vector<char*>>>>* 返回：包含指向考试记录指针的容器
 *
 * **************************************************
 */
operation_info<exam_info*>* exam_select(const char* student_id = nullptr, char* datetime_start = nullptr, char* datetime_end = nullptr);


/**
 * **************************************************
 *
 * @brief 更新成绩
 *
 * @param operation 参数：操作类对象
 *
 * @param student_id 参数：学号
 *
 * @param subject_name 参数：待修改科目名
 *
 * @param new_score 参数：新成绩
 *
 * @return operation_info<exam_info*>* 返回：操作类对象
 *
 * **************************************************
 */
operation_info<exam_info*>* exam_update(operation_info<exam_info*>* operation, char* student_id, char* subject_name, double new_score);


/**
 * **************************************************
 *
 * @brief 存储考试记录
 *
 * @param info (const exam_info*) 参数：考试记录类对象指针
 *
 * @param path (char*) 参数：如果不为空，则存储到该地址
 *
 * @return bool 返回：存储结果
 *
 * @retval true 结果：保存成功
 *
 * @retval false 结果：保存失败
 *
 * **************************************************
 */
bool exam_store(const exam_info* info, char* path = nullptr);


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
 * @param creator (const char*) 参数：日志记录创建者
 *
 * @retval None
 *
 * **************************************************
 */
void print_log(const char* logs, int severity_code = 1, const char* creator = nullptr);

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


/**
 * **************************************************
 *
 * @brief 追加配置文件记录
 *
 * @param mode (const int) 模式=1:追加账户文件路径, mode=2:追加班级文件路径, mode=3:追加成绩记录文件路径
 *
 * @param path (const char*) 合法路径（包括后缀名）
 *
 * @return bool 追加更新结果
 *
 * @retval true 追加成功
 *
 * @retval false 追加失败
 *
 * **************************************************
 */
bool properties_update(const int mode, const char* path);

#endif

