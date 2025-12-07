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
	double bill = 0.0;
	int roomNumber = 0;
	int capacity = 0;
	int duration = 0;	// Number of nights the room is booked
};

struct Room
{
	int roomNumber = 0;		// 1-total amount of rooms
	double price = 0.0;		
	bool reserved = false;
	int capacity = 0;	// 1 = single, 2 = double
	Reservation reservation;

};




// Function declarations
void ReserveRoom(std::vector<Room>& rooms, std::vector<Reservation>& reservations, int roomQuantity);
double Bill(std::vector<Room>& rooms, int nights, int roomNumber, double discountPercentage);
bool IsRoomEmpty(std::vector<Room>& rooms, int roomNumber);
template <typename T> void validateType(T& input, const std::string errMsg);
void PrintReservation(std::vector<Reservation> &reservations);
void PrintAllReservations(std::vector<Reservation>& reservations);
int GenerateResNum(std::vector<Room>& rooms);		// Generate unique reservation number
int InitializeRooms(std::vector<Room>& rooms, int);
int GetRoomQuantity();
double GetDiscountRate();
int SelectRoom(int, int);
int RoomRange(int, int);
void FindReservation(std::vector<Reservation>& reservations);
void CancelReservation(std::vector<Room>& rooms, std::vector<Reservation>&  reservations);
void RoomDataToFile(std::vector<Room>& rooms, std::vector<Reservation>& reservations);
void RoomDataFromFile(std::vector<Room>& rooms, std::vector<Reservation>& reservations);
bool ValidateName(const std::string& s);
void PrintReservationField(const std::string& label, const std::string& value, int width = 25);
int PickRoom(std::vector<Room>& rooms, int roomQuantity);
int SelectNights();
void SelectName(std::string & customerName);
void PrintBill(std::vector<Room>& rooms, int roomNumber, int nights, double bill);
void MakeReservation(std::vector<Room>& rooms, std::vector<Reservation>& reservations, std::string customerName, double bill, int roomNumber, int nights);
void UpdateResDetails(std::vector<Room>& rooms, std::vector<Reservation>& reservations, int  & roomQuantity, int & roomNumber, std::string & customerName, int & nights);
