/**
********************************************************************************
* @file         input.h
* @brief        Declaration of the function which processes user input for
*				RPS application
* @author       Maksym Koshel (maks.koshel@gmail.com)
* @date         Sep 02, 2017
********************************************************************************
*/

#ifndef _INPUT_H_
#define _INPUT_H_

#include <string>

/**
********************************************************************************
* @brief 		Converts string with number of symbol to acceptable user input
*				for this implementation which is value from 1 to 100. Function
*				name: User Input From String
* @param 		[in] str 	String will be converted
* @return 		Value from 1 to 100 on success, -1 otherwise
********************************************************************************
*/
int uifs(const std::string& str);

#endif	/* !_INPUT_H_ */
