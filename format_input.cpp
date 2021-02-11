/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file format_input.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/26 12:28:40
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "format_input.h"


 /**
  * **************************************************
  *
  * @brief Hint or no hint and then input
  *
  * @param max_str_length (int) length of string
  *
  * @param is_hint (const bool) true: print hint, false: no hint, default=false
  *
  * @param ... (const char*) tip
  *
  * @return point of char arrays or null point
  *
  * **************************************************
  */
char* input(const int max_str_length, const bool is_hint, ...)
{
	va_list ap;
	va_start(ap, is_hint);
	if (is_hint)
	{
		std::cout << va_arg(ap, const char*);
	}
	va_end(ap);

	rewind(stdin);
	// 可以吃掉缓存区字符，但是需要先行输入，保留待用
	//while ((c = getchar()) != '\n' && c != EOF)
	//{
	//	// Keep Empty
	//}
	const int count = max_str_length + 1;
	char* str = new char[count];
	fgets(str, count, stdin);

	char* find_lf = strchr(str, '\n');
	if (find_lf)
	{
		*find_lf = '\0';
	}

	rewind(stdin);
	return str;

}


/**
 * **************************************************
 *
 * @brief Single-character entry avoids reading newline characters
 *
 * @return ch (char) a char
 *
 * **************************************************
 */
char input_char()
{
	rewind(stdin);
	const unsigned char ch = getchar();
	while (getchar() != '\n')
	{
		// Keep Empty
	}
	rewind(stdin);
	return static_cast<char>(ch);
}


/**
 * **************************************************
 *
 * @brief input a char and judge it Y or N
 *
 * @param is_print_hint (const bool) whether print hint, default=false
 *
 * @param is_default_error (const bool) print error tip and wait, default=true
 *
 * @param ... (const char*) customized hint
 *
 * @return status code
 *
 * @retval 1 confirm
 *
 * @retval 0 cancel
 *
 * @retval -1 illegality
 *
 * **************************************************
 */
int input_judgment(const bool is_print_hint, const bool is_default_error, ...)
{
	if (is_print_hint)
	{
		va_list ap;
		va_start(ap, is_default_error);
		std::cout << va_arg(ap, const char*);
		va_end(ap);
	}
	
	const char choice = input_char();
	if (choice == 'Y' || choice == 'y' || choice == '\n')
	{
		return 1;
	}
	if (choice == 'N' || choice == 'n')
	{
		return 0;
	}
	if (is_default_error == true)
	{
		print_wait("Please input a correct option! ");
	}
	
	return -1;
}


/**
 * **************************************************
 *
 * @brief get a number and judge it legality
 *
 * @param max_option_length (const int) count max option - 1
 *
 * @return status code
 *
 * @retval -1 illegality input
 *
 * @retval -2 out of range
 *
 * @retval choice (int) select option
 *
 * **************************************************
 */
int input_option(const int max_option_length)
{
	const char* tmp = input(32);

	if (!is_positive_integer(tmp))
	{
		return -1;
	}
	const int choice = strtol(tmp, nullptr, 0L);
	
	if (choice < 0 || max_option_length - 1 < choice)
	{
		return -2;
	}
	
	return choice;
}


/**
 * **************************************************
 *
 * @brief input datetime
 *
 * @return char* datetime
 *
 * **************************************************
 */
char* input_datetime()
{
	char* datetime = new char[13];
	int index = 0;
	while (true)
	{
		char* tmp = input(4, true, "Please set exam years: ");
		if (is_positive_integer(tmp) && (1970 < strtol(tmp, nullptr, 0L) && strtol(tmp, nullptr, 0L) < 2090))
		{
			for (int j = 0; j < 4; j++, index++)
			{
				datetime[index] = tmp[j];
			}
			free_ptr(tmp, true);
			break;
		}
		free_ptr(tmp);
		print_wait("Please input correct date & time.");
	}
	while (true)
	{
		char* tmp = input(2, true, "Please set exam months: ");
		if (is_positive_integer(tmp) && (0 < strtol(tmp, nullptr, 0L) && strtol(tmp, nullptr, 0L) <= 12))
		{
			if (1 == strlen(tmp))
			{
				datetime[index] = '0';
				datetime[index + 1] = tmp[0];
				index += 2;
			}
			else
			{
				for (auto j = 0; j < 2; j++, index++)
				{
					datetime[index] = tmp[j];
				}
			}
			free_ptr(tmp, true);
			break;
		}
		free_ptr(tmp);
		print_wait("Please input correct date & time.");
	}
	while (true)
	{
		// If you need to make a leap year judgment, do it yourself
		char* tmp = input(2, true, "Please set exam days: ");
		if (is_positive_integer(tmp) && (0 < strtol(tmp, nullptr, 0L) && strtol(tmp, nullptr, 0L) <= 31))
		{
			if (1 == strlen(tmp))
			{
				datetime[index] = '0';
				datetime[index + 1] = tmp[0];
				index += 2;
			}
			else
			{
				for (auto j = 0; j < 2; j++, index++)
				{
					datetime[index] = tmp[j];
				}
			}
			free_ptr(tmp, true);
			break;
		}
		free_ptr(tmp);
		print_wait("Please input correct date & time.");
	}
	while (true)
	{
		char* tmp = input(2, true, "Please set exam hours: ");
		if (is_positive_integer(tmp) && (0 <= strtol(tmp, nullptr, 0L) && strtol(tmp, nullptr, 0L) < 24))
		{
			if (1 == strlen(tmp))
			{
				datetime[index] = '0';
				datetime[index + 1] = tmp[0];
				index += 2;
			}
			else
			{
				for (auto j = 0; j < 2; j++, index++)
				{
					datetime[index] = tmp[j];
				}
			}
			free_ptr(tmp, true);
			break;
		}
		free_ptr(tmp);
		print_wait("Please input correct date & time.");
	}
	while (true)
	{
		char* tmp = input(2, true, "Please set exam minutes: ");
		if (is_positive_integer(tmp) && (0 <= strtol(tmp, nullptr, 0L) && strtol(tmp, nullptr, 0L) < 60))
		{
			if (1 == strlen(tmp))
			{
				datetime[index] = '0';
				datetime[index + 1] = tmp[0];
				index += 2;
			}
			else
			{
				for (auto j = 0; j < 2; j++, index++)
				{
					datetime[index] = tmp[j];
				}
			}
			free_ptr(tmp, true);
			break;
		}
		free_ptr(tmp);
		print_wait("Please input correct date & time.");
	}
	datetime[12] = '\0';
	return datetime;
}
