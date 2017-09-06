/**
********************************************************************************
* @file         input.h
* @brief        Declaration of the function which processes user input for
*				RPS application
* @author       Maksym Koshel (maks.koshel@gmail.com)
* @date         Sep 02, 2017
********************************************************************************
*/

#include "input.h"
#include <stdexcept>

/*
********************************************************************************
*
********************************************************************************
*/
int uifs(const std::string& str)
{
	int result = -1;
	std::string::size_type sz = 0;

	try
	{
		result = std::stoi(str, &sz);
		if (sz != str.size())
		{
			result = -1;
		}
	}
	catch(const std::invalid_argument& r)
	{
		;
	}

	return result;
}