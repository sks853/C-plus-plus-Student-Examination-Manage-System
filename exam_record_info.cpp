/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file exam_record_info.cpp
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/02/02 00:55:46
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "exam_record_info.h"

/**
 * **************************************************
 *
 * @brief print record
 *
 * **************************************************
 */
void exam_record_info::print_record()
{
	std::cout << "|";
	std::cout.width(4);
	std::cout << rankings << "|";
	if (nullptr != student_name)
	{
		std::cout.width(MAXSIZE_STUDENT_NAME * 2);
		std::cout << student_name << "|";
	}
	if (nullptr != class_id)
	{
		std::cout.width(MAXSIZE_CLASS_ID);
		std::cout << class_id << "|";
	}
	if (nullptr != student_id)
	{
		std::cout.width(MAXSIZE_STUDENT_ID);
		std::cout << student_id << "|";
	}
	std::cout.width(DEFAULT_PRINT_WIDTH);
	std::cout << setiosflags(std::ios::fixed) << std::setprecision(1) << score_average << "|";
	if (!vector_score_subject.empty())
	{
		for (auto tmp : vector_score_subject)
		{
			std::cout.width(DEFAULT_PRINT_WIDTH);
			std::cout << setiosflags(std::ios::fixed) << std::setprecision(1) << tmp << "|";
		}
	}
	printf_s("\n");
}
