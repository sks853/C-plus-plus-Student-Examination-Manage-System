/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file template_operation_info.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/31 21:43:33
 *
 * @version 1.0
 *
 * **************************************************
 */

#ifndef TEMPLATE_OPERATION_INFO_H
#define TEMPLATE_OPERATION_INFO_H


template<typename T>
class operation_info
{
public:

	/**
	 * **************************************************
	 *
	 * @brief specific number
	 *
	 * **************************************************
	 */
	int info_num = -1;

	/**
	 * **************************************************
	 *
	 * @brief specific flag
	 *
	 * **************************************************
	 */
	bool info_flag = false;

	/**
	 * **************************************************
	 *
	 * @brief specific char* path
	 *
	 * **************************************************
	 */
	char* info_path = nullptr;

	/**
	 * **************************************************
	 *
	 * @brief specific char* path in vector
	 *
	 * **************************************************
	 */
	std::vector<char*> info_vector_path;

	/**
	 * **************************************************
	 *
	 * @brief specific class
	 *
	 * **************************************************
	 */
	T* info_class = new T();

	/**
	 * **************************************************
	 *
	 * @brief specific vector of class object
	 *
	 * **************************************************
	 */
	std::vector<T> info_vector_class;
	
};



#endif
