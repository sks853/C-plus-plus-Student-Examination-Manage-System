/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file manage_admin.cpp
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/23 22:31:42
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "manage_admin.h"


 /**
  * **************************************************
  *
  * @brief print menu of admin
  *
  * @param menus (menu&) self-define menu
  *
  * @retval None
  *
  * **************************************************
  */
void print_menu_admin(menu& menus)
{
	while (true)
	{
		CLEAN;
		std::cout << "Welcome, Administrator\n" << std::endl;
		print_menu(false, 1, menus.vector_admin_main, "Please select an option: ");
		switch (input_option(static_cast<int>(menus.vector_admin_main.size())))
		{
		case 0:
			std::cout << "Bye" << std::endl;
			Sleep(800);
			return;
		case 1:
			print_menu_admin_account_create(menus);
			break;
		case 2:
			print_menu_admin_account_delete();
			break;
		case 3:
			print_menu_admin_create_class();
			break;
		case 4:
			print_menu_admin_delete_class();
			break;
		case 5:
			print_menu_admin_exam_create(menus);
			break;
		case 6:
			print_menu_admin_exam_update(menus);
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
 * @brief print menu of create account
 *
 * @param menus (menu&) self-define menu
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_account_create(menu& menus)
{
	while (true)
	{
		CLEAN;

		// ---------- Start ----------
		switch (input_judgment(true, true, "Do you want to create an account? (Y/N): "))
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		// ---------- Print Menu & Select Privilege ----------
		print_menu(true, 1, menus.vector_menu_create_account, "Please set a privilege or back: ");
		const int option = input_option(static_cast<int>(menus.vector_menu_create_account.size()));
		switch (option)
		{
		case 0:
			break;
		case 1:
		case 2:
		{
			auto* student = new student_info();

			// ---------- Select ----------
			student->user_id = input(MAXSIZE_INPUT_USER_ID, true, "Please set account(user) name: ");
			if (user_select(student->user_id)->info_flag)
			{
				print_wait("Cancelled because the user already exists!");
				break;
			}

			// ---------- Input Information ----------
			student->user_password = input(MAXSIZE_INPUT_USER_PASSWORD, true, "Please set account(user) password: ");
			student->user_privilege = option;
			student->name = input(MAXSIZE_STUDENT_NAME, true, "Please set administrator/student true name: ");
			while (true)
			{
				student->id = input(MAXSIZE_STUDENT_ID, true, "Please set it administrator/student id: ");
				if (is_positive_integer(student->id))
				{
					if (!user_select(student->id, 2)->info_flag)
					{
						break;
					}
					print_wait("Cancelled because the user already exists!");
					free_ptr(student->id, true);
					continue;
				}
				free_ptr(student->id, true);
				print_wait("Please input integer.");
			}
			while (true)
			{
				student->class_id = input(MAXSIZE_CLASS_ID, true, "Please set it administrator/student class id: ");
				if (is_positive_integer(student->class_id))
				{
					break;
				}
				free_ptr(student->class_id, true);
				print_wait("Please input integer.");
			}
			while (true)
			{
				std::cout << "Please set administrator/student gender (0:Female, 1:Male): ";
				student->gender = input_option(2);
				if (0 == student->gender || 1 == student->gender)
				{
					break;
				}
				print_wait("Please input integer.");
			}

			// ---------- Reconfirm ----------
			switch (input_judgment(true, true, "Are you sure you've filled in the information? (Y/N): "))
			{
			case -1:
				free_ptr(student);
				continue;
			case 0:
				print_wait("Canceled.");
				free_ptr(student);
				return;
			case 1:
			default:
				break;
			}

			// ---------- Store Information ----------
			if (!user_store(student))
			{
				print_wait("Canceled because save errors!");
				free_ptr(student);
				return;
			}

			// ---------- Print Information ----------
			student->print_information();
			print_wait("Created Successfully! Press any key to back...\n", false);

			// ---------- Finish ----------
			free_ptr(student);
			return;
		}
		default:
			print_wait("Please input a correct option! ");
			break;
		}
	}

}


/**
 * **************************************************
 *
 * @brief print menu of delete account
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_account_delete()
{
	while (true)
	{
		CLEAN;

		// ---------- Start ----------
		switch (input_judgment(true, true, "Do you want to delete user? (Y/N) "))
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		const char* user_id = input(MAXSIZE_INPUT_USER_ID, true, "Please input the User ID to be deleted: ");

		// ---------- Reconfirm ----------
		std::cout << "Are you sure you want to delete \"" << user_id << "\"? (Y/N)" << std::endl;
		switch (input_judgment())
		{

		case 0:
			print_wait("Cancel.");
		case -1:
			free_ptr(user_id, true);
			continue;
		case 1:
		default:
			break;
		}

		// ---------- Select ----------
		auto* operation = user_select(user_id);
		if (!operation->info_flag)
		{
			print_wait("Cancel, the user id not exists!");
			free_ptr(operation);
			break;
		}

		// ---------- Delete ----------
		operation = user_delete(operation);
		if (!operation->info_flag)
		{
			print_log("Failed to delete user.", severity_code_error);
			print_wait("Failed to delete user.");
			break;
		}

		// ---------- Finish ----------
		std::cout << "Delete user id: " << user_id << std::endl;
		print_wait("Delete user account Successfully!");
		free_ptr(operation);
		free_ptr(user_id, true);
	}

}


/**
 * **************************************************
 *
 * @brief print menu of creating administrative class
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_create_class()
{
	while (true)
	{
		CLEAN;

		// ---------- Start ----------
		switch (input_judgment(true, true, "Do you want to create class? (Y/N) "))
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		auto* operation = new operation_info<class_info>;

		// ---------- Input Administrative Class Id ----------
		while (true)
		{
			operation->info_class->class_id = input(MAXSIZE_CLASS_ID, true, "Please input the id of administrative class (Digital Type): ");
			if (is_positive_integer(operation->info_class->class_id))
			{
				// ---------- Select Class Id ----------
				if (!class_select(operation->info_class->class_id)->info_flag)
				{
					break;
				}
				print_wait("Found uniform class id, please try again. ");
				free_ptr(operation->info_class->class_id, true);
				continue;
			}
			print_wait("Please input a correct option!");
			free_ptr(operation->info_class->class_id, true);
		}

		// ---------- Input Administrator ----------
		while (true)
		{
			operation->info_class->class_admin = input(MAXSIZE_INPUT_USER_ID, true, "Please select an administrator to manage administrative class: ");
			// ---------- Select User ----------
			auto* student = user_select(operation->info_class->class_admin);
			if (student->info_flag)
			{
				if (1 == student->info_class->user_privilege)
				{
					free_ptr(student);
					break;
				}
				print_wait("Select user not standard privilege, please try again. ");
				free_ptr(student);
				free_ptr(operation->info_class->class_admin, true);
				continue;
			}
			print_wait("Not found user, please try again. ");
			free_ptr(operation->info_class->class_admin, true);
		}

		// ---------- Reconfirm Administrator ----------
		std::cout << "Are you sure you want to create class and make \"" << operation->info_class->class_admin << "\" to manage class \"" << operation->info_class->class_id << "\"? (Y/N) ";
		switch (input_judgment())
		{
		case 0:
			print_wait("Cancel.");
		case -1:
			free_ptr(operation);
			continue;
		case 1:
		default:
			break;
		}

		// ---------- Input Grade ----------
		while (true)
		{
			char* tmp = input(4, true, "Please input the grade: ");
			if (is_positive_integer(tmp))
			{
				operation->info_class->class_grade = strtol(tmp, nullptr, 0L);
				free_ptr(tmp);
				break;
			}
			free_ptr(tmp);
			print_wait("Invalid scanning, please input again. ");
		}

		// ---------- Input Major ----------
		operation->info_class->class_major = input(MAXSIZE_CLASS_MAJOR, true, "Please input the major name: ");

		// ---------- Input Serial Class Id ----------
		while (true)
		{
			char* tmp = input(2, true, "Please serial class number: ");
			if (is_positive_integer(tmp))
			{
				operation->info_class->class_number = strtol(tmp, nullptr, 0L);
				free_ptr(tmp);
				break;
			}
			free_ptr(tmp);
			print_wait("Invalid scanning, please input again. ");
		}

		// ---------- Reconfirm ----------
		switch (input_judgment(true, true, "Are you sure you've finished? (Y/N) "))
		{
		case 0:
			print_wait("Cancel.");
		case -1:
			free_ptr(operation);
			continue;
		case 1:
		default:
			break;
		}

		// ---------- Store Information ----------
		class_store(operation->info_class);

		// ---------- Print Information ----------
		operation->info_class->print_info();
		print_wait("Created class Successfully!");

		// ---------- Finish ----------
		print_log("Create class.", severity_code_info);
		free_ptr(operation);
	}
}


/**
 * **************************************************
 *
 * @brief print menu of deleting administrative class
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_delete_class()
{
	while (true)
	{
		CLEAN;

		// ---------- Start ----------
		switch (input_judgment(true, true, "Do you want to delete class? (Y/N) "))
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		auto* operation = class_select(input(MAXSIZE_CLASS_ID, true, "Please input the id of administrative class (Digital Type): "));

		// ---------- Select ----------
		if (!operation->info_flag)
		{
			print_wait("Cancel, the class id not exists!");
			free_ptr(operation);
			continue;
		}
		
		// ---------- Reconfirm ----------
		std::cout << "Are you sure you want to delete class \"" << operation->info_class->class_id << "\"? (Y/N) " << std::endl;
		switch (input_judgment())
		{
		case 0:
			print_wait("Cancelled.");
		case -1:
			free_ptr(operation);
			continue;
		case 1:
		default:
			break;
		}

		// ---------- Delete ----------
		operation = class_delete(operation);
		if (!operation->info_flag)
		{
			print_log("Failed to delete class.", severity_code_error);
			print_wait("Failed to delete class.");
			free_ptr(operation);
			continue;
		}

		// ---------- Finish ----------
		print_wait("Deleted class Successfully!");
		free_ptr(operation);
	}
}


/**
 * **************************************************
 *
 * @brief according magnitude to sorted exam record of student (sort from biggest to smallest)
 *
 * @param front_info (exam_record_info*) front class object
 *
 * @param rear_info (exam_record_info*) rear class object
 *
 * @return bool rear < front ?
 *
 * @retval true front > rear
 *
 * @retval false front < rear
 *
 * **************************************************
 */
bool sort_student_exam_record(exam_record_info* front_info, exam_record_info* rear_info)
{
	return 0 <= front_info->score_average - rear_info->score_average;
}





/**
 * **************************************************
 *
 * @brief create a comprehensive examination
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_exam_create_comprehensive_examination()
{
	while (true)
	{
		CLEAN;

		// ---------- Start ----------
		switch (input_judgment(true, true, "Do you want to create comprehensive examination? (Y/N) "))
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		auto* operation = new operation_info<exam_info>;

		// 日期时间 (Date-time)
		operation->info_class->date_time = input_datetime();

		// 自动添加创建者 (Creator or administrator)
		char* tmp_admin = new char[strlen(g_vector_login_info[0]) + 1];
		strcpy_s(tmp_admin, strlen(g_vector_login_info[0]) + 1, g_vector_login_info[0]);
		operation->info_class->admin = tmp_admin;

		// 考生人数 (Count Students)
		while (true)
		{
			std::string tmp = input(3, true, "Please input amount of students: ");
			if (is_positive_integer(tmp.c_str()))
			{
				operation->info_class->count_student = strtol(tmp.c_str(), nullptr, 0L);
				break;
			}
			print_wait("Please input correctly.");
		}

		// 应考科目数 (Count majors)
		while (true)
		{
			std::string tmp = input(2, true, "Please input amounts of subject: ");
			if (is_positive_integer(tmp.c_str()))
			{
				operation->info_class->count_subject = strtol(tmp.c_str(), nullptr, 0L);
				break;
			}
			print_wait("Please input amounts of major.");
		}

		// 科目编号 (Major serial number)
		for (int i = 0; i < operation->info_class->count_subject; i++)
		{
			std::cout << "Please set the " << i + 1 << " serial id/name of subject: ";
			operation->info_class->vector_subject_serial_number.emplace_back(input(4));
		}

		// 考生记录 (Examination records of student)
		for (int i = 0; i < operation->info_class->count_student; i++)
		{
			auto* tmp_student_exam_record = new exam_record_info;
			while (true)
			{
				std::cout << "Please input the " << i + 1 << " student id: ";
				char* input_student_id = input(MAXSIZE_STUDENT_ID);
				auto* tmp_operation = user_select(input_student_id, 2);
				if (tmp_operation->info_flag)
				{
					tmp_student_exam_record->student_name = new char[strlen(tmp_operation->info_class->name) + 1];
					strcpy_s(tmp_student_exam_record->student_name, strlen(tmp_operation->info_class->name) + 1, tmp_operation->info_class->name);
					tmp_student_exam_record->student_id = input_student_id;
					tmp_student_exam_record->class_id = new char[strlen(tmp_operation->info_class->class_id) + 1];
					strcpy_s(tmp_student_exam_record->class_id, strlen(tmp_operation->info_class->class_id) + 1, tmp_operation->info_class->class_id);
					free_ptr(tmp_operation);
					break;
				}
				print_wait("Not found user. Please try input again.");
			}

			// 循环录入每科成绩 (Recycle entry of each subject score)
			for (int j = 0; j < operation->info_class->count_subject; j++)
			{
				std::cout << "Please input the score of \"" << operation->info_class->vector_subject_serial_number[j] << "\": ";
				double tmp_score = 0;
				while (true)
				{
					char* tmp = input(MAXSIZE_BUFF);
					if (std::regex_match(tmp, std::regex("^([1-9][0-9]*)+(\\.[0-9]{1,2})?$")))
					{
						tmp_score = strtod(tmp, nullptr);
						free_ptr(tmp, true);
						break;
					}
					print_wait("Please input correct number!");
				}
				tmp_student_exam_record->score_average += tmp_score;
				tmp_student_exam_record->vector_score_subject.emplace_back(tmp_score);
				if (0 == i)
				{
					operation->info_class->vector_subject_average_score.emplace_back(tmp_score);
				}
				else
				{
					operation->info_class->vector_subject_average_score[j] += tmp_score;
				}
			}

			if (0 != operation->info_class->count_student && 0 != operation->info_class->count_subject)
			{
				// 自动统计单个学生平均总分 (Calculate the average total score of each student)
				tmp_student_exam_record->score_average /= operation->info_class->count_subject;

				// 自动累加全部学生总分 (Add up the total score of all students)
				operation->info_class->average_score += tmp_student_exam_record->score_average;
			}
			
			// 存入考试记录对象 (Save the test record object)
			operation->info_class->vector_student_exam_record.emplace_back(tmp_student_exam_record);
		}

		// 自动计算全部考生总平均成绩 (Calculate the average score of all candidates)
		operation->info_class->average_score /= operation->info_class->count_student;

		// 自动计算每科平均成绩 (Calculate the average grade of each subject)
		for (int i = 0; i < operation->info_class->count_subject; i++)
		{
			operation->info_class->vector_subject_average_score[i] /= operation->info_class->count_student;
		}

		// 自动排名 (Rankings)
		std::sort(operation->info_class->vector_student_exam_record.begin(), operation->info_class->vector_student_exam_record.end(), sort_student_exam_record);
		for (int i = 0; i < operation->info_class->count_student; i++)
		{
			if (!operation->info_class->vector_student_exam_record.empty())
			{
				operation->info_class->vector_student_exam_record[i]->rankings = i + 1;
			}
		}
		
		// ---------- Reconfirm ----------
		switch (input_judgment(true, true, "Are you confirm finish? (Y/N) "))
		{
		case 0:
			print_wait("Cancelled.");
		case -1:
			return;
		case 1:
		default:
			break;
		}
		

		// ---------- Store ----------
		if (!exam_store(operation->info_class))
		{
			free_ptr(operation);
			print_wait("Save exam record failed.");
			print_log("Failed to create exam. ", severity_code_error);
			continue;
		}

		// ---------- Finish ----------
		CLEAN;
		operation->info_class->print_exam();
		free_ptr(operation);
		print_wait("Create examination successfully!");
		print_log("Create comprehensive examination successfully.", severity_code_info);
	}
}


/**
 * **************************************************
 *
 * @brief Single subject examination, including detailed examination conditions
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_exam_create_selective_examination()
{
	// TODO 选择性考试类型（还没实现，其实就是单科考试的意思，涵盖了考试每个人的大题得分情况）
	
	print_wait("Nothing.");
}


/**
 * **************************************************
 *
 * @brief create an exam
 *
 * @param menus (menu&) menu
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_exam_create(menu& menus)
{
	while (true)
	{
		CLEAN;

		print_menu(true, 1, menus.vector_menu_exam_type, "Please select a type of exam: ");
		switch (input_option(static_cast<int>(menus.vector_menu_exam_type.size())))
		{
		case 0:
			return;
		case 1:
			print_menu_admin_exam_create_comprehensive_examination();
			return;
		case 2:
			print_menu_admin_exam_create_selective_examination();
			return;
		default:
			print_wait("Please select an option!");
			break;
		}

	}
}


/**
 * **************************************************
 *
 * @brief alert student scores
 *
 * @param menus (menu&) menu
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_exam_update(menu& menus)
{
	while (true)
	{
		CLEAN;

		// ---------- Start ----------
		switch (input_judgment(true, true, "Do you want to update scores of student? (Y/N)"))
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		char* student_id;

		char* datetime_start;

		char* datetime_end;

		operation_info<exam_info*>* operation;
		
		while (true)
		{
			// ---------- Input Student Id ----------
			while (true)
			{
				student_id = input(MAXSIZE_STUDENT_ID, true, "Please input Student Id: ");
				if (std::regex_match(student_id, std::regex("^[0-9]\\d*$")))
				{
					break;
				}
				print_wait("Illegally student id input!");
				free_ptr(student_id, true);
			}

			// ---------- Input start datetime of exam ----------
			while (true)
			{
				datetime_start = input(MAXSIZE_DATETIME_LENGTH, true, "Please input start datetime: ");
				if (0 == strcmp(trim(datetime_start).c_str(), "all"))
				{
					break;
				}
				if (MAXSIZE_DATETIME_LENGTH == strlen(datetime_start) && std::regex_match(datetime_start, std::regex("^[1-9]\\d*$")))
				{
					break;
				}
				print_wait("Illegally start datetime input!");
				free_ptr(datetime_start, true);
			}

			// ---------- Input end datetime of exam ----------
			while (true)
			{
				datetime_end = input(MAXSIZE_DATETIME_LENGTH, true, "Please input end datetime: ");
				if (0 == strcmp(trim(datetime_end).c_str(), "all"))
				{
					break;
				}
				if (MAXSIZE_DATETIME_LENGTH == strlen(datetime_end) && std::regex_match(datetime_end, std::regex("^[1-9]\\d*$")))
				{
					break;
				}
				print_wait("Illegally end datetime input!");
				free_ptr(datetime_end, true);
			}

			// ---------- Select ----------
			operation = exam_select(const_cast<const char*>(student_id), datetime_start, datetime_end);

			if (!operation->info_vector_class.empty())
			{
				break;
			}

			free_ptr(datetime_end, true);
			free_ptr(datetime_start, true);
			free_ptr(student_id, true);
			free_ptr(operation);
			std::cout << "Not found user." << std::endl;
			
			switch (input_judgment(true, true, "Do you want to try again? (Y/N)"))
			{
			case -1:
				print_wait("Illegally input, cancelled.");
				return;
			case 0:
				print_wait("Cancelled.");
				return;
			case 1:
			default:
				break;
			}
		}

		// ---------- Print Old Exam ----------
		if (1 == input_judgment(true, true, "Print out all exam? (Y/N)"))
		{
			for (const auto& tmp : operation->info_vector_class)
			{
				tmp->print_exam();
				printf_s("\n\n");
			}
		}

		char* subject_serial_id;
		char* student_new_score;
		
		while (true)
		{
			// ---------- Input Subject Name ----------
			subject_serial_id = input(6, true, "Please input subject serial id: ");

			// ---------- Input New Score ----------
			
			while (true)
			{
				student_new_score = input(6, true, "Please input new score: ");
				if (std::regex_match(student_new_score, std::regex("^[0-9]+(\\.[0-9]{2})?$")))
				{
					break;
				}
				print_wait("Illegally input!");
				free_ptr(student_new_score, true);
			}

			operation = exam_update(operation, student_id, subject_serial_id, strtod(student_new_score, nullptr));
			if (operation->info_flag)
			{
				break;
			}
			print_wait("Not found or Cannot update score.");
			free_ptr(student_new_score, true);
			free_ptr(subject_serial_id, true);
		}

		int count_alter_success_file = 0;
		// ---------- Store ----------
		for (unsigned int i = 0; i < operation->info_vector_class.size(); i++)
		{
			try
			{
				if (exam_store(operation->info_vector_class[i], operation->info_vector_path[i]))
				{
					count_alter_success_file++;
				}
			}
			catch (...)
			{
				print_log("Error to save alter file.");
			}

		}

		// ---------- Print New Exam ----------
		if (1 == input_judgment(true, true, "Print out all exam? (Y/N)"))
		{
			for (const auto& tmp : operation->info_vector_class)
			{
				tmp->print_exam();
				printf_s("\n\n");
			}
		}

		std::cout << "Student ID: " << student_id << std::endl;
		std::cout << "Subject: " << subject_serial_id << std::endl;
		std::cout << "New Score: " << student_new_score << std::endl;

		std::cout << "All files: " << operation->info_vector_class.size() << std::endl;
		std::cout << "Success: " << count_alter_success_file << "\t" << "Failed: " << operation->info_vector_class.size() - count_alter_success_file << std::endl;

		print_wait("Operation success!");
		free_ptr(student_id, true);
		free_ptr(student_new_score, true);
		free_ptr(subject_serial_id, true);
		free_ptr(datetime_start, true);
		free_ptr(datetime_end, true);
		free_ptr(operation);
	}
}
