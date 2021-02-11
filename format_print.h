/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file format_print.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/26 12:24:45
 *
 * @version 1.0
 *
 * @description 封装了适合本工程的常用打印输出到控制台界面或日志
 *
 * **************************************************
 */

#ifndef FORMAT_PRINT_H
#define FORMAT_PRINT_H

#include "main.h"


/**
 * **************************************************
 *
 * @brief 打印自定义菜单
 *
 * @param is_clean (const bool) 参数：决定是否清屏
 *
 * @param tip_count (const int) 参数：默认打印提示内容的数量
 *
 * @param vectors_str (vector<const char*>) 参数：包含菜单的容器
 *
 * @param ... (const char*) 参数：（变长参数）所需提示内容，必须满足前参数
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu(bool is_clean, int tip_count, std::vector<const char*> vectors_str, ...);



/**
 * **************************************************
 *
 * @brief 打印提示内容并停止等待任意键输入后继续
 *
 * @param tip (const char*) 参数：提示内容，默认添加回车符
 *
 * @param is_default_print (bool) 参数：决定是否需要默认在提示后打印内容“按下任意键继续...”，默认=true
 *
 * @retval None
 *
 * **************************************************
 */
void print_wait(const char* tip, bool is_default_print = true);


/**
 * **************************************************
 *
 * @brief 打印提示内容并休眠，或者每秒打印一个点
 *
 * @param tip (const char*) 参数：提示内容
 *
 * @param sleep_time (const int) 参数：休眠时间，单位为毫秒，休眠一秒请输入1000
 *
 * @param have_br (const bool) 参数：打印提示后是否需要换行（回车符），默认=true
 *
 * @param is_print_point (const bool) 参数：是否在休眠期间打印“点”，点必须是休眠时间大于一秒才产生，默认=false
 *
 * @retval None
 *
 * **************************************************
 */
void print_sleep(const char* tip, int sleep_time, bool have_br = true, bool is_print_point = false);

#endif
