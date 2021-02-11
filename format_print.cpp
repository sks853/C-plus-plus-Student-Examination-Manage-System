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
 * @date 2021/01/26 12:29:25
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "format_print.h"


 /**
  * **************************************************
  *
  * @brief Print custom menu
  *
  * @param is_clean (const bool) 1: clean screen, 0: don't clean
  *
  * @param tip_count (const int) tip count
  *
  * @param vectors_str (vector<const char*>) vector of menu
  *
  * @param ... (const char*) tips
  *
  * @retval None
  *
  * **************************************************
  */
void print_menu(const bool is_clean, const int tip_count, std::vector<const char*> vectors_str, ...)
{
	if (is_clean)
	{
		CLEAN;
	}

	for (const char* str : vectors_str)
	{
		std::cout << str << std::endl;
	}

	printf_s("\n");

	va_list ap;
	va_start(ap, vectors_str);
	for (int i = 0; i < tip_count; i++)
	{
		std::cout << va_arg(ap, const char*);
		if (i < tip_count - 1)
		{
			printf_s("\n");
		}
	}
	va_end(ap);
}


/**
 * **************************************************
 *
 * @brief print tip and wait to press any key to continue or back
 *
 * @param tip (const char*) string of tips, default print '\n'
 *
 * @param is_default_print (bool) Whether to print the "press any key to continue" text, default=true
 *
 * @retval None
 *
 * **************************************************
 */
void print_wait(const char* tip, const bool is_default_print)
{
	if (is_default_print)
	{
		std::cout << tip << " Press any key to continue..." << std::endl;
	}
	else
	{
		std::cout << tip;
	}
	_getch();
}


/**
 * **************************************************
 *
 * @brief print hint and sleep or continue print point every second
 *
 * @param tip (const char*) hint
 *
 * @param sleep_time (const int) should be dormant times
 *
 * @param have_br (const bool) when print hint have or no print '\n' at the end, default=true
 *
 * @param is_print_point (const bool) whether points should be printed when sleeping, default=false
 *
 * @retval None
 *
 * **************************************************
 */
void print_sleep(const char* tip, const int sleep_time, const bool have_br, const bool is_print_point)
{
	have_br ? std::cout << tip << std::endl : std::cout << tip;

	if (is_print_point)
	{
		const clock_t start = clock();
		const int k_rate = 1000;
		int base_time = 1001;
		int base_response = 1000;
		while (true)
		{
			if ((clock() - start) % base_time == base_response)
			{
				base_time += k_rate;
				base_response += k_rate;
				printf_s(".");
			}
			if (sleep_time < clock() - start)
			{
				printf_s("\n");
				return;
			}
		}
	}

	Sleep(sleep_time);
}
