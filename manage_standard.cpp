/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file manage_standard.cpp
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/27 00:48:20
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "manage_standard.h"


/**
 * **************************************************
 *
 * @brief print menu of standard user main
 *
 * @param menus (menu&) menus
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_standard_main(menu& menus)
{
	while (true)
	{
		CLEAN;
		std::cout << "Welcome, " << g_vector_login_info[3] << "!\n" << std::endl;
		print_menu(false, 1, menus.vector_standard_main, "Please select an option: ");
		switch (input_option(static_cast<int>(menus.vector_standard_main.size())))
		{
		case 0:
			std::cout << "Bye" << std::endl;
			Sleep(800);
			return;
		case 1:
			print_menu_standard_mange_student(menus);
			break;
		case 2:
			print_menu_standard_mange_exam(menus);
			break;
		default:
			print_wait("Please select an option!");
			break;
		}

	}
}


void print_menu_standard_mange_student(menu& menus)
{
	while (true)
	{
		CLEAN;
		print_menu(false, 1, menus.vector_standard_manage_student, "Please select an option: ");
		const int option = input_option(static_cast<int>(menus.vector_standard_manage_student.size()));
		
		char* student_id = input(MAXSIZE_STUDENT_ID, true, "Please input student id: ");
		char* new_id;

		int update_value = -1;
		
		switch (option)
		{
		case 0:
			return;
		case 1:
			update_value = 4;
			new_id = input(MAXSIZE_STUDENT_ID, true, "Please input new student id: ");
			break;
		case 2:
			update_value = 5;
			new_id = input(MAXSIZE_CLASS_ID, true, "Please input new class id: ");
			break;
		default:
			print_wait("Please select an option!");
			new_id = nullptr;
			break;
		}

		if (!is_positive_integer(student_id) || !is_positive_integer(new_id))
		{
			free_ptr(student_id, true);
			free_ptr(new_id, true);
			print_wait("Invalid input!");
			continue;
		}
		
		if (1 == user_update(2, static_cast<const char*>(student_id), update_value, static_cast<const char*>(new_id)))
		{
			print_wait("Operation Successful.");
			print_log("Update Student Information.", severity_code_info, g_vector_login_info[0]);
		}
		else
		{
			print_wait("Operation Failed.");
		}
		free_ptr(student_id, true);
		free_ptr(new_id, true);
	}
}


void print_menu_standard_mange_exam(menu& menus)
{
	while (true)
	{
		CLEAN;
		print_menu(false, 1, menus.vector_standard_manage_exam, "Please select an option: ");
		switch (input_option(static_cast<int>(menus.vector_standard_manage_exam.size())))
		{
		case 0:
			return;
		case 1:
		{
			char* student_id = nullptr;
			char* datetime_start = nullptr;
			char* datetime_end = nullptr;

			if (1 == input_judgment(true, true, "Do you want to set student id? (Y/N): "))
			{
				student_id = input(MAXSIZE_STUDENT_ID, true, "Please input student id: ");
			}
			if (1 == input_judgment(true, true, "Do you want to set range of start datetime? (Y/N): "))
			{
				datetime_start = input_datetime();
			}
			if (1 == input_judgment(true, true, "Do you want to set range of end datetime? (Y/N): "))
			{
				datetime_end = input_datetime();
			}

			auto* exam_record = exam_select(student_id, datetime_start, datetime_end);
			if (exam_record->info_vector_class.empty())
			{
				free_ptr(student_id, true);
				free_ptr(datetime_start, true);
				free_ptr(datetime_end, true);
				free_ptr(exam_record);
				print_wait("Not found any exam record.");
				continue;
			}

			double range_average_scores = 0.0;
			for (auto* tmp_exam : exam_record->info_vector_class)
			{
				range_average_scores += tmp_exam->average_score;
			}
			if (!exam_record->info_vector_class.empty())
			{
				range_average_scores /= exam_record->info_vector_class.size();
			}

			int index_exam = 0;
			bool flag_viewing = true;

			while (flag_viewing)
			{
				CLEAN;
				std::cout << "Range Scores: " << range_average_scores << std::endl;
				printf_s("\n");

				exam_record->info_vector_class[index_exam]->print_exam();
				printf_s("\n");
				
				std::cout << "Page " << index_exam << std::endl;
				std::cout << "Please press <- or -> to turn page, and press ESC to exit." << std::endl;
				int show = _getch();
				if (224 == show || 0 == show)
				{
					show = _getch();
				}
				switch (show)
				{
				case 27:
					flag_viewing = false;
					break;
				case 75:
					if (0 < index_exam)
					{
						index_exam--;
					}
					break;
				case 77:
					if (index_exam < static_cast<int>(exam_record->info_vector_class.size()) - 1)
					{
						index_exam++;
					}
					break;
				default:
					break;
				}
			}
				
			break;
		}
		case 2:
		{
			print_menu_admin_exam_update(menus);
			break;
		}
		default:
			print_wait("Please select an option!");
			break;
		}
	}
}
