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
			exit(0);
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
			print_menu_admin_student_create(menus);
			break;
		case 6:
			print_menu_admin_student_delete();
			break;
		case 7:
			print_menu_admin_exam_create(menus);
			break;
		case 8:
			print_menu_admin_score_update(menus);
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
		print_menu(true, 1, menus.vector_menu_create_account, "Please set a privilege or back: ");
		const int option = input_option(static_cast<int>(menus.vector_menu_create_account.size()));
		switch (option)
		{
		case 0:
			break;;;
		case 1:
		case 2:
		{
			auto* student = new student_info();
			student->user_id = input(MAXSIZE_INPUT_USER_ID, true, "Please set account(user) name: ");
			if (user_select(student->user_id)->flag_operation)
			{
				print_wait("Cancelled because the user already exists!");
				break;;
			}
			
			student->user_password = input(MAXSIZE_INPUT_USER_PASSWORD, true, "Please set account(user) password: ");
			student->user_privilege = option;
			student->name = input(MAXSIZE_STUDENT_NAME, true, "Please set administrator/student true name: ");
			student->id = input(MAXSIZE_STUDENT_ID, true, "Please set it administrator/student id: ");
			student->class_id = input(MAXSIZE_CLASS_ID, true, "Please set it administrator/student class id: ");
			student->gender = strtol(input(1, true, "Please set administrator/student gender: "), nullptr, 0L);

			switch (input_judgment(true, true, "Are you sure you've filled in the information? (Y/N): "))
			{
			case -1:
				continue;
			case 0:
				print_wait("Canceled.");
				return;
			case 1:
			default:
				break;
			}
			
			if (!user_store(student))
			{
				print_wait("Canceled because save errors!");
				return;
			}
			student->print_information();
			print_wait("Created Successfully! Press any key to back...\n", false);
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
		const char* user_id = input(MAXSIZE_INPUT_USER_ID, true, "Please input the User ID to be deleted: ");
		
		std::cout << "Are you sure you want to delete " << user_id << "? (Y/N)" << std::endl;
		switch (input_judgment())
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		// TODO Processing Delete Account
		std::cout << "Delete user id: " << user_id << std::endl;
		print_wait("Delete user account Successfully!");
		
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

		const char* id_str = input(MAXSIZE_CLASS_ID, true, "Please input the id of administrative class (Digital Type): ");

		if (!is_positive_integer(id_str))
		{
			print_wait("Please input a correct option!");
			continue;
		}

		const char* class_admin = input(MAXSIZE_INPUT_USER_ID, true, "Please select an administrator to manage administrative class: ");

		std::cout << "Are you sure you want to create class and make \"" << class_admin << "\" to manage class \"" << id_str << "\"? (Y/N)" << std::endl;

		switch (input_judgment())
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		// TODO Processing Create Class
		std::cout << "Class Id: " << id_str << "\n" << "Class Admin: " << class_admin << std::endl;
		print_wait("Created class Successfully!");

		free_ptr(id_str, true);
		free_ptr(class_admin, true);
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

		const char* id_str = input(MAXSIZE_CLASS_ID, true, "Please input the id of administrative class: ");

		if (!is_positive_integer(id_str))
		{
			print_wait("Please input a correct option!");
			continue;
		}

		std::cout << "Are you sure you want to delete class \"" << id_str << "\"? (Y/N)" << std::endl;

		switch (input_judgment())
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		// TODO Processing Delete Class
		print_wait("Deleted class Successfully!");

		free_ptr(id_str, true);
	}
}


/**
 * **************************************************
 *
 * @brief create student information
 *
 * @param menus (const menu&) menus
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_student_create(const menu& menus)
{
	while (true)
	{
		CLEAN;

		switch (input_judgment(true, true, "Do you want to create a student information? (Y/N)"))
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		auto* student = new student_info();

		student->set_student_info(
			strtol(input(1, true, "Please input gender of this user(0?1): "), nullptr, 0L),
			input(MAXSIZE_CLASS_ID, true, "Please input class id of student: "),
			input(12, true, "Please input student id: "),
			input(12, true, "Please input student name: "),
			input(MAXSIZE_INPUT_USER_ID, true, "Please input student Account Id: ")
		);

		if (!(is_positive_integer(student->id) && is_positive_integer(student->class_id)))
		{
			print_wait("Please input integer id!");
			free_ptr(student);
			continue;
		}

		print_menu(false, 0, menus.vector_menu_select_gender);
		while (true) {
			std::cout << "Please select an option: ";
			switch (input_char())
			{
			case '0':
				student->gender = 0;
				break;
			case '1':
				student->gender = 1;
				break;
			default:
				print_wait("Please input a correct option!");
				continue;
			}
			break;
		}

		// TODO Processing Student Information Create

		std::cout << "Student Account Name: " << student->user_id << std::endl;
		std::cout << "Student Password: " << student->user_password << std::endl;
		std::cout << "Student Name: " << student->name << std::endl;
		std::cout << "Student Class: " << student->class_id << std::endl;
		std::cout << "Student Gender: " << (student->gender ? "Male" : "Female") << std::endl;;
		print_wait("Operation success!");
		free_ptr(student);
	}
}


/**
 * **************************************************
 *
 * @brief delete a student information
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_student_delete()
{
	while (true)
	{
		CLEAN;

		switch (input_judgment(true, true, "Do you want to delete a student information? (Y/N)"))
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		const char* user_id = input(MAXSIZE_INPUT_USER_ID, true, "Please input the account Name/Id of student: ");

		// TODO Processing Delete Student Info
		print_wait("Operation success!");

		free_ptr(user_id, true);
	}
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

		switch (input_judgment(true, true, "Do you want to create new exam? (Y/N)"))
		{
		case -1:
			continue;
		case 0:
			return;
		case 1:
		default:
			break;
		}

		print_menu(true, 1, menus.vector_menu_exam_type, "Please select a type of exam: ");
		switch (input_option(static_cast<int>(menus.vector_menu_exam_type.size())))
		{
		case 1:
			// TODO 综合性考试类型
			break;
		case 2:
			// TODO 选择性考试类型
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
 * @brief alert student scores
 *
 * @param menus (menu&) menu
 *
 * @retval None
 *
 * **************************************************
 */
void print_menu_admin_score_update(menu& menus)
{
	while (true)
	{
		CLEAN;

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

		print_menu(true, 1, menus.vector_menu_exam_type, "Please input Student Id: ");
		const char* student_id = input(MAXSIZE_STUDENT_ID);
		if (!is_positive_integer(student_id))
		{
			print_wait("Illegally input!");
			free_ptr(student_id, true);
			continue;
		}
		print_menu(false, true, menus.vector_menu_exam_course, "Please select a course: ");
		
		int student_subject = input_option(static_cast<int>(menus.vector_menu_exam_course.size()));
		while (student_subject <= 0)
		{
			print_wait("Please select a correct option!");
			student_subject = input_option(static_cast<int>(menus.vector_menu_exam_course.size()));
		}

		// TODO 加入时间或考试批次确定查找范围，或者确定考试类型来查找
		
		const char* score_str = input(2, true, "Please input new score: ");
		if (!is_positive_integer(score_str))
		{
			print_wait("Illegally input!");
			free_ptr(student_id, true);
			free_ptr(score_str, true);
			continue;
		}
		free_ptr(score_str);
		const int student_new_score = strtol(score_str, nullptr, 0);

		// TODO Processing Update Student's Scores
		std::cout << "Student Name: " << student_id << std::endl;
		std::cout << "Subject: " << student_subject << std::endl;
		std::cout << "New Score: " << student_new_score << std::endl;
		
		print_wait("Operation success!");
		free_ptr(student_id, true);
	}
}
