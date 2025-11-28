#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "validateType.h"

// Room structure
struct Reservation
{
	int reservationNumber = 0;
	std::string customer = "";		// Customer name
	double discountPercentage = 0.0;
	int roomNumber = 0;
	int capacity = 0;
};

struct Room
{
	int roomNumber = 0;		// 1-total amount of rooms
	double price = 100.0; // Default price		
	bool reserved = false;
	int capacity = 0;	// 1 = single, 2 = double
	Reservation reservation;

};




// Function declarations
void ReserveRoom(std::vector<Room>& rooms, std::vector<Reservation>& reservations, int roomQuantity);
double Bill(Room (&room), int nights, int roomNumber);
bool IsRoomEmpty(std::vector<Room>& rooms, int roomNumber);
template <typename T> void validateType(T& input, const std::string errMsg);
void PrintReservation(std::vector<Reservation> &reservations);
void PrintAllReservations(std::vector<Reservation>& reservations);
int GenerateResNum(std::vector<Room>& rooms);		// Generate unique reservation number
int InitializeRooms(std::vector<Room>& rooms);
int GetRoomQuantity();



