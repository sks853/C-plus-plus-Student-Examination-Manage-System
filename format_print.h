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
 * @description ��װ���ʺϱ����̵ĳ��ô�ӡ���������̨�������־
 *
 * **************************************************
 */

#ifndef FORMAT_PRINT_H
#define FORMAT_PRINT_H

#include "main.h"


/**
 * **************************************************
 *
 * @brief ��ӡ�Զ���˵�
 *
 * @param is_clean (const bool) �����������Ƿ�����
 *
 * @param tip_count (const int) ������Ĭ�ϴ�ӡ��ʾ���ݵ�����
 *
 * @param vectors_str (vector<const char*>) �����������˵�������
 *
 * @param ... (const char*) ���������䳤������������ʾ���ݣ���������ǰ����
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu(bool is_clean, int tip_count, std::vector<const char*> vectors_str, ...);



/**
 * **************************************************
 *
 * @brief ��ӡ��ʾ���ݲ�ֹͣ�ȴ��������������
 *
 * @param tip (const char*) ��������ʾ���ݣ�Ĭ����ӻس���
 *
 * @param is_default_print (bool) �����������Ƿ���ҪĬ������ʾ���ӡ���ݡ��������������...����Ĭ��=true
 *
 * @retval None
 *
 * **************************************************
 */
void print_wait(const char* tip, bool is_default_print = true);


/**
 * **************************************************
 *
 * @brief ��ӡ��ʾ���ݲ����ߣ�����ÿ���ӡһ����
 *
 * @param tip (const char*) ��������ʾ����
 *
 * @param sleep_time (const int) ����������ʱ�䣬��λΪ���룬����һ��������1000
 *
 * @param have_br (const bool) ��������ӡ��ʾ���Ƿ���Ҫ���У��س�������Ĭ��=true
 *
 * @param is_print_point (const bool) �������Ƿ��������ڼ��ӡ���㡱�������������ʱ�����һ��Ų�����Ĭ��=false
 *
 * @retval None
 *
 * **************************************************
 */
void print_sleep(const char* tip, int sleep_time, bool have_br = true, bool is_print_point = false);

#endif
