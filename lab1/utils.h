#pragma once
#include <iostream>
#include <string>

template <typename T>
T GetCorrectNumber(std::string text, T min, T max)
{
	T param;
	std::cout << text;
	while (!(std::cin >> param) || param < min || param > max)
	{
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cout << text;
	}
	return param;
}