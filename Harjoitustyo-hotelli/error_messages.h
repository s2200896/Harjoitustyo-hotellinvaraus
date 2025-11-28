#pragma once
#include <string>

inline std::string room_errmsg(int maxRooms) {
	return "Invalid room number. Please enter a number between 1 and " + std::to_string(maxRooms) + ": ";
}
const std::string nights_errmsg = "Invalid amount of nights. Please enter a positive number: ";
const std::string choice_errmsg = "Invalid input. Please enter [1] for Yes, [0] for No:  ";
const std::string common_errmsg = "Unfortunately I can't help you with that. Please select an option from the list: ";
