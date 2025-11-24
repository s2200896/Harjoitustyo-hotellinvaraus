#pragma once
#include <iostream>
#include <string>
#include <limits>

// Room structure
struct Room
{
	static const int quantity = 10;		// Total number of rooms
	double price = 100.0;				// Default price for a room
	int roomStatus[quantity] = { 0 };	// Initialize with 0, 0 = empty room, 1 = reserved room
	int reservationNumber;

};

struct Reservation
{
	int reservationNumber;
	std::string customerName;
};


// Function declarations
void ReserveRoom(Room& hotel);
double Bill(Room& hotel, int nights);
bool IsRoomEmpty(const Room& room, int);
template <typename T> void validateType(T& input, const std::string errMsg);



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