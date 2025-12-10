#include <iostream>
#include "header.h"

void MakeReservation(std::vector<Room>& rooms, std::vector<Reservation>& reservations, std::string customerName, double bill, int roomNumber, int nights) {

	// Reserve room
	const int index = roomNumber - 1;	// Convert roomNumber to 0 based vector index
	int reservationNumber = GenerateResNum(rooms);
	rooms[index].reservation.reservationNumber = reservationNumber;
	rooms[index].reserved = true;
	rooms[index].reservation.customer = customerName;

	// Create new reservation
	Reservation newReservation;
	newReservation.reservationNumber = reservationNumber;
	newReservation.customer = customerName;
	newReservation.discountPercentage = rooms[index].reservation.discountPercentage;
	newReservation.bill = bill;
	newReservation.roomNumber = roomNumber;
	newReservation.capacity = rooms[index].capacity;
	newReservation.duration = nights;

	// Update reservations vector
	reservations.push_back(newReservation);

	std::cout << "\nRoom " << roomNumber << " is reserved for " << rooms[index].reservation.customer << ".\n";

}