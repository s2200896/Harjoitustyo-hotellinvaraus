#pragma once
#include <string>

inline std::string room_errmsg(int minRoom, int maxRoom) {
	return "Invalid room number. Please enter a number between " + std::to_string(minRoom) + " and " + std::to_string(maxRoom) + ": ";
}
const std::string nights_errmsg = "Invalid amount of nights. Please enter a number between 1 and 31: ";
const std::string choice_errmsg = "Invalid input. Please enter [1] for Yes, [0] for No:  ";
const std::string assignRoom_errmsg = "Invalid input. Please enter [1] to pick the room by yourself, [0] to have the room assigned to you: ";
const std::string roomType_errmsg = "Invalid input. Please enter [1] to select single room, [2] to select double room: ";
const std::string common_errmsg = "Unfortunately I can't help you with that. Please select an option from the list: ";
const std::string searchCondition_errmsg = "Invalid input. Please enter [1] to search by reservation number, [0] to search by name: ";
const std::string reservationNumber_errmsg = "Invalid input. Please enter a valid reservation number: ";
