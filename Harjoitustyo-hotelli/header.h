#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <vector>

// Room structure
struct Reservation
{
	int reservationNumber;
	std::string customer;		//customer name
	double discountPercentage;
};

struct Room
{
	int roomNumber;		// 1-total amount of rooms
	double price = 100.0; // Default price		
	bool reserved;		// 1 if reserved
	Reservation reservation;

};


const int roomQuantity = 10;	// Total amount of rooms


// Function declarations
void ReserveRoom(Room (&rooms)[roomQuantity]);
double Bill(Room (&room), int nights, int roomNumber);
bool IsRoomEmpty(Room(&rooms)[roomQuantity], int roomNumber);
template <typename T> void validateType(T& input, const std::string errMsg);
void PrintReservation();
int GenerateResNum();		// Generated unique reservation number



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