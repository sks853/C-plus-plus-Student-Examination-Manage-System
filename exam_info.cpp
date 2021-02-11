/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file exam_info.cpp
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/02/02 00:36:58
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "exam_info.h"

/**
 * **************************************************
 *
 * @brief print exam
 *
 * **************************************************
 */
void exam_info::print_exam()
{
	std::cout << "********** ********** ********** ********** ********** ********** ********** **********" << std::endl;
	std::cout << "|";
	std::cout.width(12);
	std::cout << "Exam Date" << "|";
	std::cout.width(MAXSIZE_INPUT_USER_ID);
	std::cout << "Admin" << "|";
	std::cout.width(DEFAULT_PRINT_WIDTH);
	std::cout << "Student" << "|";
	std::cout.width(DEFAULT_PRINT_WIDTH);
	std::cout << "Average" << "|";
	std::cout.width(DEFAULT_PRINT_WIDTH);
	std::cout << "Majors" << "|";
	std::cout << "\n";

	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "|";
	if (nullptr != date_time)
	{
		std::cout.width(12);
		std::cout << date_time << "|";
	}
	if (nullptr != admin)
	{
		std::cout.width(MAXSIZE_INPUT_USER_ID);
		std::cout << admin << "|";
	}
	std::cout.width(DEFAULT_PRINT_WIDTH);
	std::cout << count_student << "|";
	std::cout.width(DEFAULT_PRINT_WIDTH);
	std::cout << setiosflags(std::ios::fixed) << std::setprecision(1) << average_score << "|";
	std::cout.width(DEFAULT_PRINT_WIDTH);
	std::cout << count_subject << "|";
	std::cout << "\n";

	std::cout << "********** ********** ********** ********** ********** ********** ********** **********" << std::endl;
	std::cout << "|";	
	if (!vector_subject_serial_number.empty())
	{
		for (auto* tmp : vector_subject_serial_number)
		{
			std::cout.width(DEFAULT_PRINT_WIDTH);
			std::cout << tmp << "|";
		}
	}
	std::cout << "\n";

	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "|";
	if (!vector_subject_average_score.empty())
	{
		for (auto tmp : vector_subject_average_score)
		{
			std::cout.width(DEFAULT_PRINT_WIDTH);
			std::cout << setiosflags(std::ios::fixed) << std::setprecision(1) << tmp << "|";
		}
	}
	std::cout << "\n";

	std::cout << "********** ********** ********** ********** ********** ********** ********** **********" << std::endl;
	std::cout << "|";
	std::cout.width(4);
	std::cout << "R&K" << "|";
	std::cout.width(MAXSIZE_STUDENT_NAME * 2);
	std::cout << "Name" << "|";
	std::cout.width(MAXSIZE_CLASS_ID);
	std::cout << "Class" << "|";
	std::cout.width(MAXSIZE_STUDENT_ID);
	std::cout << "ID" << "|";
	std::cout.width(DEFAULT_PRINT_WIDTH);
	std::cout << "Score" << "|";
	for (int i = 0; i < count_subject; i++)
	{
		std::cout.width(DEFAULT_PRINT_WIDTH);
		std::cout << vector_subject_serial_number[i] << "|";
	}
	printf_s("\n");

	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	if (!vector_student_exam_record.empty())
	{
		for (auto* tmp : vector_student_exam_record)
		{
			tmp->print_record();
		}
	}

	std::cout << "********** ********** ********** ********** ********** ********** ********** **********" << std::endl;
}
