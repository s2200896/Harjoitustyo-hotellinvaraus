#pragma once
#include <iostream>
#include <limits>
#include <string>


// Continously reads input into "input" until a valid value of type T is entered 
// if the extraction fails customer will be prompted with the provided error message
template <typename T> void validateType(T& input, const std::string errMsg) {

	std::cin >> input;

	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << errMsg;

		std::cin >> input;
	}

}