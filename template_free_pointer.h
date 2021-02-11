/**
 * **************************************************
 *
 * @coding UTF-8
 *
 * @file template_free_pointer.h
 *
 * @author HDM
 *
 * @copyright HDM
 *
 * @date 2021/01/26 12:20:41
 *
 * @version 1.0
 *
 * **************************************************
 */

#ifndef TEMPLATE_FREE_POINTER_H
#define TEMPLATE_FREE_POINTER_H

 /**
  * **************************************************
  *
  * @brief free pointer values or pointer arrays
  *
  * @param p (T*) any pointer
  *
  * @param is_array (const bool) is array, default=false
  *
  * @retval None
  *
  * **************************************************
  */
template <typename T>
void free_ptr(T* p, const bool is_array = false)
{

	if (nullptr != p)
	{
		if (is_array)
		{
			delete[] p;
			p = nullptr;
			return;
		}
		delete p;
		p = nullptr;
	}
}

#endif
