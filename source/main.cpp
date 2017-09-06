/**
********************************************************************************
* @file         main.cpp
* @brief        Entry point to application
* @author       Maksym Koshel (maks.koshel@gmail.com)
* @date         Sep 02, 2017
********************************************************************************
*/

#include <iostream>

#include "playground.h"
#include "player.h"
#include "input.h"

int main(int argc, char* argv[])
{
	int result = 0;

	do
	{
		std::cout << "Welcome to RPS (Rock-Piper-Scisors) game" << std::endl;
		std::cout << "Please, enter number of iterations you would like to do:"
				<< std::endl;

		std::string user_input;
		std::cin >> user_input;

		int games = uifs(user_input);
		if (games <= 0 || 100 < games)
		{
			result = 1;
			std::cerr << "Please, enter number of games you would like to play "
				"in range [1-100]" << std::endl;
			break;
		}
		std::cout << "Number of games will be player: " << games << std::endl;

		Machine m;
		Human h;
		Playground p(games);
		try
		{
			p.play(m, h);
		}
		catch(const std::runtime_error& r)
		{
			std::cerr << "Application exits. Reason: " << r.what() << std::endl;
			result = 1;
			break;
		}

	} while(0);

	// Supress warnings
	(void) argc;
	(void) argv;
	return result;
}