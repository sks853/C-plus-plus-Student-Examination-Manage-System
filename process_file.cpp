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


// define global value of login information
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
					if ('\r' == token[strlen(token) - 1] || '\n' == token[strlen(token) - 1])
					{
						token[strlen(token) - 1] = '\0';
					}
					vector_tmp.emplace_back(token);
					token = strtok_s(nullptr, ",", &next_context);
				}

				if (0 == strcmp(user_name, vector_tmp[0]) && 0 == strcmp(user_password, vector_tmp[1]))
				{
					g_vector_login_info.swap(vector_tmp);
					f.close();
					return true;
				}
			}
			f.close();
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
 * @param uuid (const char*) input user name or user student id
 *
 * @param mode (const int) select mode, according user name=1 or user student id=2, default= 1
 *
 * @return operation_info<student_info>* pointer of a class and object template
 *
 * **************************************************
 */
operation_info<student_info>* user_select(const char* uuid, const int mode)
{
	auto* operation = new operation_info<student_info>;
	
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
					if ('\r' == token[strlen(token) - 1] || '\n' == token[strlen(token) - 1])
					{
						token[strlen(token) - 1] = '\0';
					}
					vector_tmp.emplace_back(token);
					token = strtok_s(nullptr, ",", &next_context);
				}

				switch (mode)
				{
				case 1:
					if (0 != strcmp(uuid, vector_tmp[0]))
					{
						continue;
					}
					break;
				case 2:
					if (0 != strcmp(uuid, vector_tmp[4]))
					{
						continue;
					}
					break;
				default:
					print_log("Error select user param. ", severity_code_error);
					f.close();
					return operation;
				}
				
				try
				{
					char* tmp_str_line = new char[tmp_file.length() + 1];
					strcpy_s(tmp_str_line, tmp_file.length() + 1, tmp_file.c_str());
					operation->info_path = tmp_str_line;
					operation->info_class->user_id = const_cast<char*>(vector_tmp[0]);
					operation->info_class->user_password = const_cast<char*>(vector_tmp[1]);
					operation->info_class->user_privilege = strtol(const_cast<char*>(vector_tmp[2]), nullptr, 0L);
					operation->info_class->name = const_cast<char*>(vector_tmp[3]);
					operation->info_class->id = const_cast<char*>(vector_tmp[4]);
					operation->info_class->class_id = const_cast<char*>(vector_tmp[5]);
					operation->info_class->gender = strtol(const_cast<char*>(vector_tmp[6]), nullptr, 0L);
					operation->info_flag = true;
				}
				catch (std::exception&)
				{
					print_log("Load information file errors!", severity_code_error);
				}

			}
			f.close();
		}
		catch (std::exception&)
		{
			print_log("Not found file of accounts", severity_code_error);
		}
	}
	return operation;
}


/**
 * **************************************************
 *
 * @brief store account information
 *
 * @param student (const student_info*) class pointer of student_info
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
		f << student->gender << "\r\n";
		
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
 * @brief delete user information if exist
 *
 * @param operation (operation_info<student_info>*) operation information class
 *
 * @return operation_info<student_info>* operation information class
 *
 * **************************************************
 */
operation_info<student_info>* user_delete(operation_info<student_info>* operation)
{
	operation->info_flag = false;
	std::fstream f;
	try
	{
		f.open(operation->info_path, std::ios::in | std::ios::binary);
		if (!f.is_open())
		{
			return operation;
		}

		std::string tmp_string;
		std::vector<std::string> tmp_vector_line;
		while (std::getline(f, tmp_string))
		{
			char* context = new char[tmp_string.length() + 1];
			char* next_context;
			strcpy_s(context, tmp_string.length() + 1, tmp_string.c_str());
			char* token = strtok_s(context, ",", &next_context);
			std::vector<const char*> vector_tmp;
			while (token != nullptr)
			{
				if ('\r' == token[strlen(token) - 1] || '\n' == token[strlen(token) - 1])
				{
					token[strlen(token) - 1] = '\0';
				}
				vector_tmp.emplace_back(token);
				token = strtok_s(nullptr, ",", &next_context);
			}

			if (0 != strcmp(operation->info_class->user_id, vector_tmp[0]))
			{
				tmp_vector_line.emplace_back(tmp_string);
			}
		}
		f.close();
		f.open(operation->info_path, std::ios::out | std::ios::trunc | std::ios::binary);
		for (const auto& tmp : tmp_vector_line)
		{
			f << tmp << "\r\n";
		}
		f.close();
		operation->info_flag = true;
	}
	catch (const std::exception& e)
	{
		print_log(e.what(), severity_code_error);
	}
	return operation;
}


/**
 * **************************************************
 *
 * @brief select a class information then return
 *
 * @param class_id (const char*) input class admin id
 *
 * @return operation_info<class_info>* pointer of a class and object template
 *
 * **************************************************
 */
operation_info<class_info>* class_select(const char* class_id)
{
	auto* operation = new operation_info<class_info>;

	for (const auto& tmp_line : g_vector_file_path_class)
	{
		std::string tmp_file = trim(tmp_line);
		try
		{
			std::fstream f;
			f.open(tmp_file, std::ios::in | std::ios::binary);
			if (!f.is_open())
			{
				print_log("Can't open an class file when load class information", severity_code_warning);
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
					if ('\r' == token[strlen(token) - 1] || '\n' == token[strlen(token) - 1])
					{
						token[strlen(token) - 1] = '\0';
					}
					vector_tmp.emplace_back(token);
					token = strtok_s(nullptr, ",", &next_context);
				}

				if (0 != strcmp(class_id, vector_tmp[0]))
				{
					continue;
				}
				try
				{
					char* tmp_str_line = new char[tmp_file.length() + 1];
					strcpy_s(tmp_str_line, tmp_file.length() + 1, tmp_file.c_str());
					operation->info_path = tmp_str_line;
					operation->info_class->class_id = const_cast<char*>(vector_tmp[0]);
					operation->info_class->class_admin = const_cast<char*>(vector_tmp[1]);
					operation->info_class->class_grade = strtol(const_cast<char*>(vector_tmp[2]), nullptr, 0L);
					operation->info_class->class_major = const_cast<char*>(vector_tmp[3]);
					operation->info_class->class_number = strtol(const_cast<char*>(vector_tmp[4]), nullptr, 0L);
					operation->info_flag = true;
				}
				catch (std::exception&)
				{
					print_log("Load class information file errors!", severity_code_error);
				}

			}
			f.close();
		}
		catch (std::exception&)
		{
			print_log("Not found file of class", severity_code_error);
		}
	}
	return operation;
}


/**
 * **************************************************
 *
 * @brief save class information to file
 *
 * @param classes (const class_info*) class pointer of class_info
 *
 * @return bool store status
 *
 * @retval true save successful
 *
 * @retval false save failed
 *
 * **************************************************
 */
bool class_store(const class_info* classes)
{
	std::fstream f;
	try
	{
		if (g_vector_file_path_account.empty())
		{
			print_log("Create an account file, because account files is empty", severity_code_info);
			f.open(PATH_FOLDER_CLASS"class_0.csv", std::ios::out | std::ios::binary);
		}
		else
		{
			f.open(g_vector_file_path_class[g_vector_file_path_class.size() - 1], std::ios::out | std::ios::app | std::ios::binary);
		}
		if (!f.is_open())
		{
			return false;
		}

		f << classes->class_id << ",";
		f << classes->class_admin << ",";
		f << classes->class_grade << ",";
		f << classes->class_major << ",";
		f << classes->class_number << "\r\n";

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
 * @brief delete class information if exist
 *
 * @param operation (operation_info<class_info>*) operation information class
 *
 * @return operation_info<class_info>* operation information class, if success then operation->info_flag=true
 *
 * **************************************************
 */
operation_info<class_info>* class_delete(operation_info<class_info>* operation)
{
	operation->info_flag = false;
	std::fstream f;
	try
	{
		f.open(operation->info_path, std::ios::in | std::ios::binary);
		if (!f.is_open())
		{
			return operation;
		}

		std::string tmp_string;
		std::vector<std::string> tmp_vector_line;
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

			if (0 != strcmp(operation->info_class->class_id, vector_tmp[0]))
			{
				tmp_vector_line.emplace_back(tmp_string);
			}
		}
		f.close();
		f.open(operation->info_path, std::ios::out | std::ios::trunc | std::ios::binary);
		for (const auto& tmp : tmp_vector_line)
		{
			f << trim(tmp) << "\r\n";
		}
		f.close();
		operation->info_flag = true;
	}
	catch (const std::exception& e)
	{
		print_log(e.what(), severity_code_error);
	}
	return operation;
}


/**
 * **************************************************
 *
 * @brief choose select mode according amount of params
 *
 * 根据传递值选择查找模式
 * 值表示如下：————表示为nullptr
 *
 * 0=0000：传入参数有【————】【————】【————】 全为nullptr （默认查询全部考试）
 *
 * 1=0001：传入参数有【学生学号】【————】【————】 （默认查询指定学生参与的全部考试）
 *
 * 2=0010：传入参数有【————】【开始日期】【————】 （默认查询在这日期之后的所有考试）
 *
 * 3=0011：传入参数有【学生学号】【开始日期】【————】 （默认查询在这日期之后的当前学生考试）
 *
 * 4=0100：传入参数有【————】【————】【结束日期】 （默认查询在这日期之前的所有考试）
 *
 * 5=0101：传入参数有【学生学号】【————】【结束日期】 （默认查询在这日期之前的当前学生考试）
 *
 * 6=0110：传入参数有【————】【开始日期】【结束日期】 （默认查询指定范围日期内的所有考试）
 *
 * 7=0111：传入参数有【学生学号】【开始日期】【结束日期】 （默认查询指定学生在范围日期内的考试）
 *
 * @return int 0-7
 *
 * **************************************************
 */
int set_select_mode(const char* student_name, const char* datetime_start, const char* datetime_end)
{

	auto select_mode = 0;

	if (nullptr != student_name)
	{
		select_mode |= 0x01;
	}

	if (nullptr != datetime_start)
	{
		select_mode |= 0x02;
	}

	if (nullptr != datetime_end)
	{
		select_mode |= 0x04;
	}

	return select_mode;
}


/**
 * **************************************************
 *
 * @brief split line to field
 *
 * @param tmp_line (std::string&) string line 
 *
 * @return std::vector<char*> vector of include split string
 *
 * **************************************************
 */
std::vector<char*> split_line(std::string& tmp_line)
{
	std::vector<char*> tmp_vector_line_field;

	char* context = new char[tmp_line.length() + 1];
	char* next_context;

	strcpy_s(context, tmp_line.length() + 1, tmp_line.c_str());

	try
	{
		char* token = strtok_s(context, ",", &next_context);
		while (token != nullptr)
		{
			std::string token_trim = trim(token);
			char* tmp_const_char_field = new char[token_trim.length() + 1];
			strcpy_s(tmp_const_char_field, token_trim.length() + 1, token_trim.c_str());
			tmp_vector_line_field.emplace_back(tmp_const_char_field);
			token = strtok_s(nullptr, ",", &next_context);
		}
	}
	catch (...)
	{
		print_log("Error split field.");
	}

	return tmp_vector_line_field;
}


/**
 * **************************************************
 *
 * @brief compare datetime in range
 *
 * @param datetime_compare (char*) for compare datetime
 *
 * @param datetime_start (char*) datetime of start
 *
 * @param datetime_end (char*) datetime of end
 *
 * @return bool
 *
 * **************************************************
 */
bool datetime_compare(char* datetime_compare, char* datetime_start, char* datetime_end)
{
	const std::regex tmp_regex("^[1-9]\\d*$");
	try
	{
		if (!(std::regex_match(datetime_compare, tmp_regex) && std::regex_match(datetime_start, tmp_regex) && std::regex_match(datetime_end, tmp_regex)))
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}

	return (0 >= strcmp(datetime_start, datetime_compare)) && (0 >= strcmp(datetime_compare, datetime_end));
}


/**
 * **************************************************
 *
 * @brief select all exam records or by datetime
 *
 * @param student_id (const char*) student id, default=nullptr
 *
 * @param datetime_start (const char*) start datetime, default=nullptr
 *
 * @param datetime_end (const char*) end datetime, default=nullptr
 * 
 * @return operation_info<std::vector<std::vector<std::vector<char*>>>>* vector include class object of exam_info pointer, field
 *
 * **************************************************
 */
operation_info<exam_info*>* exam_select(const char* student_id, char* datetime_start, char* datetime_end)
{
	auto* operation = new operation_info<exam_info*>;

	// 查询处理模式
	const int select_mode = set_select_mode(student_id, datetime_start, datetime_end);

	// 如果没有考试记录则直接返回结果 (if there is no examination record, the result is returned directly)
	if (g_vector_file_path_record.empty())
	{
		try
		{
			free_ptr(operation->info_class);
		}
		catch (...)
		{
			print_log("Cannot free std::vector<exam_info* in examination records selecting.");
		}
		return operation;
	}

	// 遍历配置文件存储的每个record记录
	for (const auto& file_path_record : g_vector_file_path_record)
	{
		// 去掉尾部空白符，判断路径是否合法
		std::string file_path_record_trim = trim(file_path_record);
		if (!is_valid_file_path(file_path_record_trim.c_str()))
		{
			continue;
		}

		// 以二进制流只读方式打开文件，打不开继续遍历下一个文件
		std::fstream f;
		try
		{
			f.open(file_path_record_trim.c_str(), std::ios::in | std::ios::binary);
			if (!f.is_open())
			{
				continue;
			}
		}
		catch (...)
		{
			print_log("Cannot load record file");
			continue;
		}

		// ------------------------------------------- 下面是文件打开后处理 -------------------------------------------

		// 当前行下标
		int index_line = 0;

		// 判断日期是否为待查文件
		bool flag_is_select_file_datetime = true;

		// 判断文件是否包含待查学号
		bool flag_is_select_file_student_id = false;

		// 临时存放的当前行内容
		std::string tmp_context_line;

		// 考试记录类对象
		auto* exam = new exam_info();

		// 读取文件的每一行，一次一行
		while (flag_is_select_file_datetime && std::getline(f, tmp_context_line))
		{
			// 行数自增1
			index_line++;

			// 读取完一行并分割字段
			std::vector<char*> tmp_line_field = split_line(tmp_context_line);
			
			if (!tmp_line_field.empty())
			{
				// 捕获考试基本信息
				if (1 == index_line)
				{
					char tmp_infinity_datetime_great[] = "99999999999999";
					char tmp_infinity_datetime_small[] = "00000000000000";
					try
					{
						switch (select_mode)
						{
						case 2:
						case 3:
							if (!datetime_compare(tmp_line_field[0], datetime_start, tmp_infinity_datetime_great))
							{
								flag_is_select_file_datetime = false;
							}
							break;
						case 4:
						case 5:
							if (!datetime_compare(tmp_line_field[0], tmp_infinity_datetime_small, datetime_end))
							{
								flag_is_select_file_datetime = false;
							}
							break;
						case 6:
						case 7:
							if (!datetime_compare(tmp_line_field[0], datetime_start, datetime_end))
							{
								flag_is_select_file_datetime = false;
							}
							break;
						default:
							break;
						}
					}
					catch (const std::exception& e)
					{
						print_log(e.what());
						print_log("Error select exam in get student information in line = 3");
					}


					// 将基本考试信息装入考试类对象
					if (flag_is_select_file_datetime)
					{
						try
						{
							exam->date_time = tmp_line_field[0];
							exam->admin = tmp_line_field[1];
							exam->count_student = strtol(tmp_line_field[2], nullptr, 0L);
							exam->average_score = strtod(tmp_line_field[3], nullptr);
							exam->count_subject = strtol(tmp_line_field[4], nullptr, 0L);
						}
						catch (const std::exception& e)
						{
							print_log(e.what());
							print_log("Error exam record file.");
						}
					}
				}

				try
				{
					// 读取科目编号和科目平均成绩
					switch (index_line)
					{
					case 2:
						for (const auto& tmp : tmp_line_field)
						{
							exam->vector_subject_serial_number.emplace_back(tmp);
						}
						break;
					case 3:
						for (const auto& tmp : tmp_line_field)
						{
							exam->vector_subject_average_score.emplace_back(strtod(tmp, nullptr));
						}
						break;
					default:
						break;
					}
				}
				catch (const std::exception& e)
				{
					print_log(e.what());
					print_log("Error in select exam when index line 2.");
				}

				// 开始捕获学生信息
				if (3 < index_line)
				{
					try
					{
						switch (select_mode)
						{
						case 0:
						case 2:
						case 4:
						case 6:
							// 不需要查找学号则直接置为true
							flag_is_select_file_student_id = true;
							break;
						default:
							if (std::regex_match(tmp_line_field[3], std::regex("^[1-9]\\d*$")))
							{
								if (0 == strcmp(student_id, tmp_line_field[3]))
								{
									flag_is_select_file_student_id = true;
								}
							}
							break;
						}
					}
					catch (const std::exception& e)
					{
						print_log(e.what());
						print_log("Error in get student information in line > 3");
					}

					// 将学生考试类对象装入考试类对象
					try
					{
						auto* student = new exam_record_info();
						student->rankings = strtol(tmp_line_field[0], nullptr, 0L);
						student->student_name = tmp_line_field[1];
						student->class_id = tmp_line_field[2];
						student->student_id = tmp_line_field[3];
						student->score_average = strtod(tmp_line_field[4], nullptr);
						for (unsigned int i = 5; i < tmp_line_field.size(); i++)
						{
							student->vector_score_subject.emplace_back(strtod(tmp_line_field[i], nullptr));
						}
						exam->vector_student_exam_record.emplace_back(student);
					}
					catch (const std::exception& e)
					{
						print_log(e.what());
						print_log("Error in get student information in line > 3");
					}
				} // 大于第三行的某一行if
			} // 仍在单个文件某一行中if
		} // 仍在单个文件循环内while

		// 如果日期对上了，学号也对上了，那么认为这个文件是需要的，存入考试记录类对象
		if (flag_is_select_file_student_id && flag_is_select_file_datetime)
		{
			char* tmp_path = new char[file_path_record_trim.length() + 1];
			strcpy_s(tmp_path, file_path_record_trim.length() + 1, file_path_record_trim.c_str());
			operation->info_vector_path.emplace_back(tmp_path);
			operation->info_vector_class.emplace_back(exam);
		}
	} // 遍历每个文件for

	if (operation->info_vector_class.empty())
	{
		operation->info_flag = false;
	}
	else
	{
		operation->info_flag = true;
	}

	return operation;
}


/**
 * **************************************************
 *
 * @brief exam update scores
 *
 * @param operation object class pointer
 *
 * @param student_id student id
 *
 * @param subject_name subject name
 *
 * @param new_score new score
 *
 * @return operation_info<exam_info*>* object class pointer
 *
 * **************************************************
 */
operation_info<exam_info*>* exam_update(operation_info<exam_info*>* operation, char* student_id, char* subject_name, double new_score)
{
	operation->info_flag = false;

	if (operation->info_vector_class.empty())
	{
		return operation;
	}

	int index_subject = -1;

	// 遍历考试类对象
	for (auto* tmp : operation->info_vector_class)
	{
		// 遍历科目编号容器
		for (unsigned int j = 0; j < tmp->vector_subject_serial_number.size(); j++)
		{
			// 看看要找的下标在哪
			if (0 == strcmp(tmp->vector_subject_serial_number[j], subject_name))
			{
				index_subject = static_cast<int>(j);
			}
		}
		
		// 如果有下标说明找到了，那就试着更改成绩，当然前提是得先找到这个学生
		if (-1 != index_subject)
		{
			// 遍历每个学生类对象
			for (auto* student : tmp->vector_student_exam_record)
			{
				// 比较看看是不是要找的学生学号，如果不是那就继续（有点套娃）
				if (0 != strcmp(student->student_id, student_id))
				{
					continue;
				}

				double old_score_subject;
				double old_score_average;

				// 找到了就直接更改就好了，如果更改报错异常那就是文件的问题，对了，还没做剔除内容结尾空白符的处理
				try
				{
					old_score_subject = student->vector_score_subject[index_subject];
					old_score_average = student->score_average;
					student->vector_score_subject[index_subject] = new_score;
				}
				catch (...)
				{
					print_log("Cannot update exam score.");
					continue;
				}

				// 除了这个学生这一科要改，学生平均总分、全部人单科平均分、全部人平均总分也得一起改
				if (0 < tmp->count_subject && 0 < tmp->count_student)
				{
					operation->info_flag = true;

					// 学生平均总分 = 当前学生平均总分 + (新的单科分数 - 旧的单科分数) / 科目总数
					student->score_average = student->score_average + (new_score - old_score_subject) / tmp->count_subject;
					
					// 考试总平均分 = 当前考试总平均分 + (新的学生平均总分 - 旧的学生平均总分) / 学生总人数
					tmp->average_score = tmp->average_score + (student->score_average - old_score_average) / tmp->count_student;

					// 单科平均分 = 当前某科总平均分 + (新的单科分数 - 旧的单科分数) / 学生总人数
					tmp->vector_subject_average_score[index_subject] = tmp->vector_subject_average_score[index_subject] + (new_score - old_score_subject) / tmp->count_student;
				}
			}
		}
	}
	
	return operation;
}


/**
 * **************************************************
 *
 * @brief save exam record to file
 *
 * @param info (const exam_info*) class object of exam record
 *
 * @param path (char*) if not nullptr save to this path
 *
 * @return bool save success ?
 *
 * @retval true save successful
 *
 * @retval false save failed
 *
 * **************************************************
 */
bool exam_store(const exam_info* info, char* path)
{
	std::fstream f;
	char tmp_path[] = PATH_FOLDER_RECORD"exam_0.csv";

	try
	{
		if (nullptr == path)
		{
			if (g_vector_file_path_record.empty())
			{
				print_log("Create an record file, because not record files exist", severity_code_info);
				f.open(PATH_FOLDER_RECORD"exam_0.csv", std::ios::out | std::ios::trunc | std::ios::binary);
			}
			else
			{
				std::vector<int> tmp_vector_index;
				for (const auto& tmp_exam_path : g_vector_file_path_record)
				{
					auto tmp_trim_path = trim(tmp_exam_path);
					tmp_vector_index.emplace_back(tmp_trim_path.c_str()[tmp_trim_path.length() - 1 - 4] - '0');
				}
				if (!tmp_vector_index.empty())
				{
					std::sort(tmp_vector_index.begin(), tmp_vector_index.end(), std::less<>());
					tmp_path[strlen(tmp_path) - 1 - 4] = static_cast<char>((tmp_vector_index[tmp_vector_index.size() - 1] + 1) + '0');
				}
				f.open(tmp_path, std::ios::out | std::ios::trunc | std::ios::binary);
			}
		}
		else
		{
			f.open(path, std::ios::out | std::ios::trunc | std::ios::binary);
		}
		
		if (!f.is_open())
		{
			return false;
		}

		f << info->date_time << "," << info->admin << "," << info->count_student << "," << info->average_score << "," << info->count_subject << "\r\n";
		if (!info->vector_subject_serial_number.empty())
		{
			for (const auto* tmp : info->vector_subject_serial_number)
			{
				f << tmp;
				if (0 != strcmp(tmp, info->vector_subject_serial_number.back()))
				{
					f << ",";
				}
				else
				{
					f << "\r\n";
				}
			}
		}

		if (!info->vector_subject_average_score.empty())
		{
			for (unsigned int i = 0; i < info->vector_subject_average_score.size(); i++)
			{
				f << info->vector_subject_average_score[i];
				if (i != info->vector_subject_average_score.size() - 1)
				{
					f << ",";
				}
				else
				{
					f << "\r\n";
				}
			}
		}
		
		if (!info->vector_student_exam_record.empty())
		{
			for (const auto& tmp : info->vector_student_exam_record)
			{
				f << tmp->rankings << ",";
				f << tmp->student_name << ",";
				f << tmp->class_id << ",";
				f << tmp->student_id << ",";
				f << tmp->score_average << ",";

				for (unsigned int i = 0; i < tmp->vector_score_subject.size(); i++)
				{
					f << tmp->vector_score_subject[i];
					if (i != tmp->vector_score_subject.size() - 1)
					{
						f << ",";
					}
					else
					{
						f << "\r\n";
					}
				}
			}
		}
		f.close();

		if (!properties_update(3, tmp_path))
		{
			return false;
		}
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
	
	g_ptr_log << "[" << tmp_content << "]" << tmp_code << logs << std::endl;
	
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
		std::string tmp = trim(tmp_line);

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

		if (is_valid_file_path(tmp.c_str()))
		{
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


/**
 * **************************************************
 *
 * @brief update properties file
 *
 * @param mode (const int) mode=1:account, mode=2:class, mode=3:record
 *
 * @param path (const char*) valid path
 *
 * @return bool update successfully?
 *
 * @retval true update successful
 *
 * @retval false update failed
 *
 * **************************************************
 */
bool properties_update(const int mode, const char* path)
{
	if (!is_valid_file_path(path))
	{
		return false;
	}

	switch (mode)
	{
	case 1:
		g_vector_file_path_account.emplace_back(trim(path));
		break;
	case 2:
		g_vector_file_path_class.emplace_back(trim(path));
		break;
	case 3:
		g_vector_file_path_record.emplace_back(trim(path));
		break;
	default:
		return false;
	}

	std::fstream f;
	f.open(PATH_FILE_PROPERTIES, std::ios::out | std::ios::trunc | std::ios::binary);

	f << SIGN_PROPERTIES_ACCOUNT << "\r\n";
	if (!g_vector_file_path_account.empty())
	{
		for (const auto& tmp : g_vector_file_path_account)
		{
			f << tmp << "\r\n";
		}
	}
	else
	{
		f << "\n";
	}

	f << SIGN_PROPERTIES_CLASS << "\r\n";
	if (!g_vector_file_path_account.empty())
	{
		for (const auto& tmp : g_vector_file_path_class)
		{
			f << tmp << "\r\n";
		}
	}
	else
	{
		f << "\n";
	}

	f << SIGN_PROPERTIES_RECORD << "\r\n";
	if (!g_vector_file_path_account.empty())
	{
		for (const auto& tmp : g_vector_file_path_record)
		{
			f << tmp << "\r\n";
		}
	}
	else
	{
		f << "\n";
	}

	f.close();
	return true;
}

