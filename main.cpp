/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file main.cpp
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/23 10:23:00
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "main.h"


 /**
  * **************************************************
  *
  * @brief determine if the input string is a positive integer
  *
  * @param str (const char*) string
  *
  * @return bool is positive integer
  *
  * @retval true positive integer
  *
  * @retval false no positive integer
  *
  * **************************************************
  */
bool is_positive_integer(const char* str)
{
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		if (str[i] < '0' || '9' < str[i])
		{
			return false;
		}
	}
	return true;
}


/**
 * **************************************************
 *
 * @brief print menu of login
 *
 * @return (int) privileges of user
 *
 * **************************************************
 */
int login_verify()
{
	int attempts = 3;
	while (attempts--)
	{
		CLEAN;
		std::cout << "Welcome to Student Manage System\n" << std::endl;
		try
		{
			char* input_name = input(MAXSIZE_INPUT_USER_ID, true, "Please input UserName/ID: ");
			char* input_password = input(MAXSIZE_INPUT_USER_PASSWORD, true, "Please input Password: ");

			// Administrator ROOT PRIVILEGE
			if (0 == strcmp("root", input_name) && 0 == strcmp("root", input_password))
			{
				g_vector_login_info.emplace_back("root");
				g_vector_login_info.emplace_back("root");
				g_vector_login_info.emplace_back("0");
				g_vector_login_info.emplace_back("root");
				g_vector_login_info.emplace_back("0000000000000");
				g_vector_login_info.emplace_back("000000");
				g_vector_login_info.emplace_back("1");
				return privilege_admin;
			}

			if (user_verify(input_name, input_password))
			{
				std::cout << "Verify Successful!" << std::endl;
				print_log("Login Successful.", severity_code_info, g_vector_login_info[0]);
				Sleep(1000);
				return strtol(g_vector_login_info[2], nullptr, 0L);
			}
			print_sleep("Verify Failed! Please Try again!", 1500);
			print_log("Failed to try login.", severity_code_info);
			free_ptr(input_name, true);
			free_ptr(input_password, true);
		}
		catch (char)
		{
			print_wait("Error!");
			exit(-1);
		}
	}
	print_sleep("Sorry, you don't have chance! ", 3500, false, true);
	exit(0);
}


/**
 * **************************************************
 *
 * @brief main function
 *
 * @param [int]{__argc} argument count
 *
 * @param [char]{*__argv[]} argument value
 *
 * @return exit normally
 *
 * **************************************************
 */
int main(int __argc, char* __argv[])
{
	init_log();
	init_properties();
	
	try
	{
		menu menus = menu();
		switch (login_verify())
		{
		case privilege_admin:
			print_menu_admin(menus);
			break;
		case privilege_standard:
			break;
		case privilege_read:
			print_menu_read_main(menus);
			break;
		default:
			return -1;
		}
	}
	catch (std::exception& e)
	{
		print_log(e.what());
		return -1;
	}

	return 0;
}
