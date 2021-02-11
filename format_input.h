/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file format_input.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/26 12:25:57
 *
 * @version 1.0
 *
 * @description 封装了适合本工程的常用格式化的输入
 *
 * **************************************************
 */

#ifndef FORMAT_INPUT_H
#define FORMAT_INPUT_H

#include "main.h"


 /**
  * **************************************************
  *
  * @brief 提示输出并输入指定长度的内容
  *
  * @param max_str_length (int) 参数：允许最大输入长度
  *
  * @param is_hint (const bool) 参数：是否打印提示内容，默认=false（不打印）
  *
  * @param ... (const char*) 参数：（可变参数）提示内容
  *
  * @return 返回：指向字符数组的指针或空指针
  *
  * **************************************************
  */
char* input(int max_str_length, bool is_hint = false, ...);


/**
 * **************************************************
 *
 * @brief 单字符输入，避免读取回车符
 *
 * @return (char) 返回：读取到的第一个有效字符
 *
 * **************************************************
 */
char input_char();


/**
 * **************************************************
 *
 * @brief 选择判断输入的是是还是否，即（Y/N）->（确定/取消）并返回结果，或者打印非法输入提示
 *
 * @param is_print_hint (const bool) 参数：是否需要在输入前打印提示，默认=false，需要打印则必须在变长参数传入字符串
 *
 * @param is_default_error (const bool) 参数：是否需要打印默认报错并停止等待按下任意键继续，默认=true
 *
 * @param ... (const char*) 参数：（可变参数）输入前的提示内容，仅限一条
 *
 * @return status code 返回：状态码
 *
 * @retval 1 结果：确定
 *
 * @retval 0 结果：取消
 *
 * @retval -1 结果：不合法输入
 *
 * **************************************************
 */
int input_judgment(bool is_print_hint = false, bool is_default_error = true, ...);


/**
 * **************************************************
 *
 * @brief 输入数字选项并返回错误码或者选择结果（筛选数字类型）
 *
 * @param max_option_length (const int) 参数：最多有多少个选项（默认从0开始到所设长度-1，例如希望允许选项范围为[0,12)则设该参数值为12，因此可选范围为[0,11]）
 *
 * @return status code 返回：状态码
 *
 * @retval -1 结果：非法输入
 *
 * @retval -2 结果：输入越界
 *
 * @retval choice (int) 结果：所选项的值
 *
 * **************************************************
 */
int input_option(int max_option_length);

#endif
