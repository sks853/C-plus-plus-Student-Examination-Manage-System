/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file process_file.cpp
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/28 14:22:58
 *
 * @version 1.0
 *
 * **************************************************
 */

#include "process_file.h"


std::vector<const char*> g_vector_login_info;


/**
 * **************************************************
 *
 * @brief verify login
 *
 * @param user_name (const char*) input user name
 *
 * @param user_password (const char*) input user password
 *
 * @return bool whether login success or fail
 *
 * @retval true successful
 *
 * @retval false failed
 *
 * **************************************************
 */
bool user_verify(const char* user_name, const char* user_password)
{
	for (const auto&  tmp_line: g_vector_file_path_account)
	{
		std::string tmp_file;
		if ('\r' == tmp_line.c_str()[tmp_line.length() - 1] || '\n' == tmp_line.c_str()[tmp_line.length() - 1] || '\t' == tmp_line.c_str()[tmp_line.length() - 1])
		{
			tmp_file = tmp_line.substr(0, tmp_line.length() - 1);
		}
		else
		{
			tmp_file.assign(tmp_line);
		}
		try
		{
			std::fstream f;
			f.open(tmp_file, std::ios::in | std::ios::binary);
			if (!f.is_open())
			{
				print_log("Can't open an account file when load accounts to verify", severity_code_warning);
				continue;
			}

			std::string tmp_string;

			while (std::getline(f, tmp_string))
			{
				char* context = new char[tmp_string.length() + 1];
				char* next_context;
				strcpy_s(context, tmp_string.length() + 1, tmp_string.c_str());
				char* token = strtok_s(context, ",", &next_context);
				std::vector<const char*> vector_tmp;
				while (token != nullptr)
				{
					vector_tmp.emplace_back(token);
					token = strtok_s(nullptr, ",", &next_context);
				}

				f.close();
				if (0 == strcmp(user_name, vector_tmp[0]) && 0 == strcmp(user_password, vector_tmp[1]))
				{
					g_vector_login_info.swap(vector_tmp);
					return true;
				}
			}
		}
		catch (std::exception&)
		{
			print_log("File of accounts not found.", severity_code_error);
		}
	}
	return false;
}


/**
 * **************************************************
 *
 * @brief select a student user information then return
 *
 * @param user_name (const char*) input user name
 *
 * @return student_info* pointer of a class and object
 *
 * **************************************************
 */
student_info* user_select(const char* user_name)
{
	auto* student = new student_info();
	for (const auto& tmp_line : g_vector_file_path_account)
	{
		std::string tmp_file = trim(tmp_line);
		try
		{
			std::fstream f;
			f.open(tmp_file, std::ios::in | std::ios::binary);
			if (!f.is_open())
			{
				print_log("Can't open an account file when load accounts to verify", severity_code_warning);
				continue;
			}

			std::string tmp_string;

			while (std::getline(f, tmp_string))
			{
				char* context = new char[tmp_string.length() + 1];
				char* next_context;
				strcpy_s(context, tmp_string.length() + 1, tmp_string.c_str());
				char* token = strtok_s(context, ",", &next_context);
				std::vector<const char*> vector_tmp;
				while (token != nullptr)
				{
					vector_tmp.emplace_back(token);
					token = strtok_s(nullptr, ",", &next_context);
				}
				
				if (0 != strcmp(user_name, vector_tmp[0]))
				{
					continue;
				}
				try
				{
					student->user_id = const_cast<char*>(vector_tmp[0]);
					student->user_password = const_cast<char*>(vector_tmp[1]);
					student->user_privilege = strtol(const_cast<char*>(vector_tmp[2]), nullptr, 0L);
					student->name = const_cast<char*>(vector_tmp[3]);
					student->id = const_cast<char*>(vector_tmp[4]);
					student->class_id = const_cast<char*>(vector_tmp[5]);
					student->gender = strtol(const_cast<char*>(vector_tmp[6]), nullptr, 0L);
					student->flag_operation = true;
				}
				catch (std::exception&)
				{
					print_log("Load information errors!", severity_code_error);
				}

			}
			f.close();
		}
		catch (std::exception&)
		{
			print_log("File of accounts not found and error", severity_code_error);
		}
	}
	return student;
}


/**
 * **************************************************
 *
 * @brief store account information
 *
 * @param student (const student_info*)
 *
 * @return bool whether store successfully
 *
 * @retval true successful
 *
 * @retval false failed
 *
 * **************************************************
 */
bool user_store(const student_info* student)
{
	std::fstream f;
	try
	{
		if (g_vector_file_path_account.empty())
		{
			print_log("Create an account file, because account files is empty", severity_code_info);
			f.open(PATH_FOLDER_ACCOUNTS"account_0.csv", std::ios::out | std::ios::binary);
		}
		else
		{
			f.open(g_vector_file_path_account[g_vector_file_path_account.size() - 1], std::ios::out | std::ios::app | std::ios::binary);
		}
		if (!f.is_open())
		{
			return false;
		}
		
		f << student->user_id << ",";
		f << student->user_password << ",";
		f << student->user_privilege << ",";
		f << student->name << ",";
		f << student->id << ",";
		f << student->class_id << ",";
		f << student->gender << "\n";
		
		f.close();
	}
	catch (const std::exception& e)
	{
		print_log(e.what(), severity_code_error);
		return false;
	}

	return true;
}


/**
 * **************************************************
 *
 * @brief removes trailing formatting characters
 *
 * @param str (string&) strings
 * 
 * @return string
 *
 * **************************************************
 */
std::string trim(const std::string& str)
{
	std::string tmp;
	if ('\r' == str.c_str()[str.length() - 1] || '\n' == str.c_str()[str.length() - 1] || '\t' == str.c_str()[str.length() - 1])
	{
		tmp = str.substr(0, str.length() - 1);
	}
	else
	{
		tmp.assign(str);
	}
	return tmp;
}


 /**
  * **************************************************
  *
  * @brief print out log to log file
  *
  * @param logs (const char*) log message
  *
  * @param severity_code (const int) level of severity, code from 0->2 is [Error]->[Warning]->[Info], default=1
  *
  * @retval None
  *
  * **************************************************
  */
void print_log(const char* logs, const int severity_code)
{
	tm* time_tm = new tm;
	time_t now_time = time(nullptr);
	char tmp_content[256];
	char tmp_code[24];
	localtime_s(time_tm, &now_time);
	strftime(tmp_content, sizeof(tmp_content), "%Y-%m-%d %H:%M:%S", time_tm);

	switch (severity_code)
	{
	case severity_code_error:
		strcpy_s(tmp_code, 24, "[Error]");
		break;
	case severity_code_warning:
		strcpy_s(tmp_code, 24, "[Warning]");
		break;
	case severity_code_info:
		strcpy_s(tmp_code, 24, "[Info]");
		break;
	default:
		strcpy_s(tmp_code, 24, "[Unknown]");
	}
	
	g_ptr_log << tmp_code << "[" << tmp_content << "]" << logs << std::endl;
	
	if (g_ptr_log.fail())
	{
		system("cls");
		std::cout << "Can't write to log" << std::endl;
		exit(-1);
	}

	free_ptr(time_tm);
}


/**
 * **************************************************
 *
 * @brief verify file path validity
 * 
 * @param file_path (const char*) file path
 *
 * @return bool
 *
 * @retval true legal
 *
 * @retval false illegal
 *
 * **************************************************
 */
bool is_valid_file_path(const char* file_path)
{
	try {
        const std::regex reg_double_slash_path("^.(\\\\[a-zA-Z0-9_]+)+(.csv)$");
		const std::regex reg_back_slant_path("^^.(/[a-zA-Z0-9_]+)+(.csv)$");
		if (std::regex_match(file_path, reg_double_slash_path) || std::regex_match(file_path, reg_back_slant_path)) {
			return true;
		}
	}
	catch (std::regex_error& e) {
		std::cout << e.what() << "\ncode: " << e.code() << std::endl;;
        return false;
	}
	return false;
}


/**
 * **************************************************
 *
 * @brief read properties and store to static values
 *
 * @retval None
 *
 * **************************************************
 */
void init_properties()
{
    std::fstream f;
    try
    {
		f.open(PATH_FILE_PROPERTIES, std::ios::in | std::ios::binary);
    	if (!f.is_open() || f.fail())
    	{
			std::cout << "Initialize fail!" << std::endl;
			print_log("Can't open properties. From function \"init_properties()\"", severity_code_error);
			exit(-1);
    	}
    }
    catch (std::exception& e)
    {
		std::cout << "Can't open properties!" << "\n" << e.what() << std::endl;
		print_log("Initialize fail, can't open properties. From function \"init_properties()\"", severity_code_error);
		exit(-1);
    }

    std::string tmp_line;

    auto line_mode = 0;
    auto count_db_account = 0;
	auto count_db_class = 0;
    auto count_db_record = 0;

    while (std::getline(f, tmp_line))
    {
		std::string tmp;
    	if ('\r' == tmp_line.c_str()[tmp_line.length() - 1] || '\n' == tmp_line.c_str()[tmp_line.length() - 1] || '\t' == tmp_line.c_str()[tmp_line.length() - 1])
    	{
			tmp = tmp_line.substr(0, tmp_line.length() - 1);
    	}
    	else
    	{
			tmp.assign(tmp_line);
    	}
        if (0 == strcmp(tmp.c_str(), SIGN_PROPERTIES_ACCOUNT))
        {
            line_mode = 0;
            continue;
        }

		if (0 == strcmp(tmp.c_str(), SIGN_PROPERTIES_CLASS))
		{
			line_mode = 1;
			continue;
		}

        if (0 == strcmp(tmp.c_str(), SIGN_PROPERTIES_RECORD))
        {
            line_mode = 2;
            continue;
        }

        if (!is_valid_file_path(tmp.c_str()))
        {
            continue;
        }

        switch (line_mode)
        {
        case 0:
            count_db_account++;
            g_vector_file_path_account.emplace_back(tmp);
            break;
		case 1:
			count_db_class++;
			g_vector_file_path_class.emplace_back(tmp);
			break;
        case 2:
            count_db_record++;
            g_vector_file_path_record.emplace_back(tmp);
            break;
        default:
            ;
        }

    }

    if (0 == count_db_account)
    {
		print_log("Path list of account is empty. From function \"init_properties()\"", severity_code_info);
    }

	if (0 == count_db_class)
	{
		print_log("Path list of class is empty. From function \"init_properties()\"", severity_code_info);
	}

    if (0 == count_db_record)
    {
		print_log("Path list of record is empty. From function \"init_properties()\"", severity_code_info);
    }

    f.close();
}


/**
 * **************************************************
 *
 * @brief init pointer of log file
 *
 * @retval None
 *
 * **************************************************
 */
void init_log()
{
	if (_access("./data/config", 0))
	{
		_mkdir("./data/config");
	}
	g_ptr_log.open(PATH_FILE_LOGS, std::ios::out | std::ios::app | std::ios::binary);
	if (!g_ptr_log.is_open() || g_ptr_log.fail())
	{
		std::cout << "Can't open log file!" << std::endl;
		exit(-1);
	}
}


















///////////////////////////////////////////////////////////////////////////////////////
constexpr auto k_file_score = "./data/grade0.csv";
///////////////////////////////////////////////////////////////////////////////////////
void test()
{
    std::fstream f;
	f.open(k_file_score, std::ios::in | std::ios::out | std::ios::binary);
	if (!f.is_open())
	{
		std::cout << "Already Open, Open Error!" << std::endl;
		exit(-1);
	}

	std::string tmp_string;
	std::vector<std::string> vector_title;
	std::vector<std::string> vector_lines;
	std::vector<std::vector <std::string>> vector_table;

	int index_line = -1;

	while (std::getline(f, tmp_string))
	{
		if (index_line == -1)
		{
			char* context = new char[tmp_string.length() + 1];
			char* next_context;
			strcpy_s(context, tmp_string.length() + 1, tmp_string.c_str());
			char* token = strtok_s(context, ",", &next_context);
			while (token != nullptr)
			{
				vector_title.emplace_back(token);
				token = strtok_s(nullptr, ",", &next_context);
			}
			free_ptr(token, true);
			free_ptr(context, true);
			index_line++;
			continue;
		}
		index_line++;
		vector_lines.emplace_back(tmp_string);
	}


	for (const auto& str : vector_title)
	{
		std::cout << "\t" << str;
	}
	printf_s("\n---------- ---------- ---------- ----------\n");

	for (const auto& str : vector_lines)
	{
		std::cout << str << std::endl;
	}
	printf_s("\n---------- ---------- ---------- ----------\n");
	
	f.close();
}

