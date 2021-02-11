/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file class_info.cpp
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/02/01 16:24:30
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "class_info.h"



/**
 * **************************************************
 *
 * @brief print all information if it not null
 *
 * @retval None
 *
 * **************************************************
 */
void class_info::print_info()
{
	if (nullptr != class_id)
	{
		std::cout << class_id << " ";
	}
	if (nullptr != class_admin)
	{
		std::cout << class_admin << " ";
	}
	if (-1 != class_grade)
	{
		std::cout << class_grade << " ";
	}
	if (nullptr != class_major)
	{
		std::cout << class_major << " ";
	}
	if (-1 != class_number)
	{
		std::cout << class_number << " ";
	}
	printf_s("\n");
}
