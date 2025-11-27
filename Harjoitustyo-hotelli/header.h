#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "validateType.h"

// Room structure
struct Reservation
{
	int reservationNumber;
	std::string customer;		//customer name
	double discountPercentage;
	int roomNumber;
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
void ReserveRoom(Room (&rooms)[roomQuantity], std::vector<Reservation>& reservations);
double Bill(Room (&room), int nights, int roomNumber);
bool IsRoomEmpty(Room(&rooms)[roomQuantity], int roomNumber);
template <typename T> void validateType(T& input, const std::string errMsg);
void PrintReservation(std::vector<Reservation> &reservations);
void PrintAllReservations(std::vector<Reservation>& reservations);
int GenerateResNum(Room (&rooms)[roomQuantity]);		// Generate unique reservation number



