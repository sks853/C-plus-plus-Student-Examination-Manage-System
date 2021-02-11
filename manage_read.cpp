/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file manage_read.cpp
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/02/05 22:00:20
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "manage_read.h"


 /**
  * **************************************************
  *
  * @brief print menu of read-only main
  *
  * @param menus (menu&) menus
  *
  * @retval None
  *
  * **************************************************
  */
void print_menu_read_main(menu& menus)
{
	while (true)
	{
		CLEAN;
		std::cout << "Welcome, " << g_vector_login_info[3] << "!\n" << std::endl;
		print_menu(false, 1, menus.vector_read_main, "Please select an option: ");
		switch (input_option(static_cast<int>(menus.vector_read_main.size())))
		{
		case 0:
			std::cout << "Bye" << std::endl;
			Sleep(800);
			return;
		case 1:
			print_menu_personal_information_manage(menus);
			break;
		case 2:
			print_menu_read_statistics_examination(menus);
			break;
		default:
			print_wait("Please select an option!");
			break;
		}

	}
}


/**
 * **************************************************
 *
 * @brief print menu of personal information and processing
 *
 * @param menus (menu&) menus
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_personal_information_manage(menu& menus)
{
	while (true)
	{
		CLEAN;

		for (unsigned int i = 0; i < g_vector_login_info.size(); i++)
		{
			if (1 == i)
			{
				std::cout << menus.vector_read_info_manage_tip[i] << std::setw(strlen(g_vector_login_info[i])) << std::setfill('*') << "" << std::endl;
			}
			else
			{
				std::cout << menus.vector_read_info_manage_tip[i] << g_vector_login_info[i] << std::endl;
			}
		}
		printf_s("\n");

		print_menu(false, 1, menus.vector_read_info_manage_alter, "Please select an option: ");
		switch (input_option(static_cast<int>(menus.vector_read_info_manage_alter.size())))
		{
		case 0:
			return;
		case 1:
		{
			char* new_user_name;

			while (true)
			{
				new_user_name = input(MAXSIZE_INPUT_USER_ID, true, "Please input new user name: ");
				if (!user_select(new_user_name)->info_flag)
				{
					break;
				}
				print_wait("User name Exists.");
			}

			auto* operation = user_select(g_vector_login_info[0]);
			if (!operation->info_flag || operation->info_vector_class.empty())
			{
				free_ptr(operation);
				print_wait("Cannot founded user.");
				free_ptr(new_user_name, true);
				break;
			}

			for (unsigned int i = 0; i < operation->info_vector_class.size(); i++)
			{
				if (0 == strcmp(operation->info_vector_class[i].user_id, g_vector_login_info[0]))
				{
					operation->info_vector_class[i].user_id = new_user_name;
				}
			}

			user_store(operation->info_vector_class, const_cast<const char*>(operation->info_path));

			std::cout << "New User Name: " << new_user_name << std::endl;
			print_log("User alter user name.", severity_code_info, g_vector_login_info[0]);
			free_ptr(new_user_name, true);
			print_wait("Operation Success! Please login again.");
			exit(0);
		}
		case 2:
		{
			char* new_user_password = input(MAXSIZE_INPUT_USER_PASSWORD, true, "Please input new user password: ");

			auto* operation = user_select(g_vector_login_info[0]);

			if (!operation->info_flag || operation->info_vector_class.empty())
			{
				free_ptr(operation);
				print_wait("Cannot founded user.");
				free_ptr(new_user_password, true);
				break;
			}

			for (unsigned int i = 0; i < operation->info_vector_class.size(); i++)
			{
				if (0 == strcmp(operation->info_vector_class[i].user_id, g_vector_login_info[0]))
				{
					operation->info_vector_class[i].user_password = new_user_password;
				}
			}

			user_store(operation->info_vector_class, const_cast<const char*>(operation->info_path));

			std::cout << "New user password: " << new_user_password << std::endl;
			print_log("User alter user password.", severity_code_info, g_vector_login_info[0]);
			free_ptr(new_user_password, true);

			print_wait("Operation Success! Please login again.", false);
			exit(0);
		}
		default:
			print_wait("Please select an option!");
			break;
		}
	}
}


/**
 * **************************************************
 *
 * @brief print menu of statistics examination and processing
 *
 * @param menus (menu&) menus
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_read_statistics_examination(menu& menus)
{
	auto* exam_all = exam_select(g_vector_login_info[4]);

	double average_rankings = 0;
	double average_scores = 0.0;

	if (exam_all->info_flag)
	{
		for (auto* tmp_exam : exam_all->info_vector_class)
		{
			for (auto* tmp_student : tmp_exam->vector_student_exam_record)
			{
				if (0 == strcmp(tmp_student->student_id, g_vector_login_info[4]))
				{
					average_rankings += tmp_student->rankings;
					average_scores += tmp_student->score_average;
				}
			}
		}

		if (!exam_all->info_vector_class.empty())
		{
			average_rankings /= exam_all->info_vector_class.size();
			average_scores /= exam_all->info_vector_class.size();
		}
	}

	free_ptr(exam_all);

	while (true)
	{
		CLEAN;
		std::cout << "ID: " << g_vector_login_info[4] << std::endl;
		std::cout << "Name: " << g_vector_login_info[3] << std::endl;
		std::cout << "Rankings: " << average_rankings << std::endl;
		std::cout << "Scores: " << average_scores << std::endl;

		char* datetime_start = nullptr;
		char* datetime_end = nullptr;

		print_menu(false, 1, menus.vector_read_exam_statistics, "Please select an option: ");
		switch (input_option(static_cast<int>(menus.vector_read_exam_statistics.size())))
		{
		case 0:
			return;
		case 1:
			break;
		case 2:
			if (1 == input_judgment(true, true, "Do you want to set range of start datetime? (Y/N): "))
			{
				datetime_start = input_datetime();
			}
			if (1 == input_judgment(true, true, "Do you want to set range of end datetime? (Y/N): "))
			{
				datetime_end = input_datetime();
			}
			break;
		default:
			break;
		}

		auto* exam_record = exam_select(g_vector_login_info[4], datetime_start, datetime_end);
		if (exam_record->info_vector_class.empty())
		{
			print_wait("Not found any exam record.");
			continue;
		}

		double range_average_rankings = 0.0;
		double range_average_scores = 0.0;

		for (auto* tmp_exam : exam_record->info_vector_class)
		{
			for (auto* tmp_student : tmp_exam->vector_student_exam_record)
			{
				if (0 == strcmp(tmp_student->student_id, g_vector_login_info[4]))
				{
					range_average_rankings += tmp_student->rankings;
					range_average_scores += tmp_student->score_average;
				}
			}
		}

		if (!exam_record->info_vector_class.empty())
		{
			range_average_rankings /= exam_record->info_vector_class.size();
			range_average_scores /= exam_record->info_vector_class.size();
		}

		int index_exam = 0;
		bool flag_viewing = true;

		while (flag_viewing)
		{
			CLEAN;
			std::cout << "ID: " << g_vector_login_info[4] << std::endl;
			std::cout << "Name: " << g_vector_login_info[3] << std::endl;
			std::cout << "Range Rankings: " << range_average_rankings << std::endl;
			std::cout << "Range Scores: " << range_average_scores << std::endl;
			printf_s("\n");

			exam_record->info_vector_class[index_exam]->print_exam();
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

	}
}

