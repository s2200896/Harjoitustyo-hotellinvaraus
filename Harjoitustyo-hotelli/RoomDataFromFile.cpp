#include <iostream>
#include <fstream>
#include <sstream>
#include "header.h"

// Read rooms/reservations to vectors
void RoomDataFromFile(std::vector<Room>& rooms, std::vector<Reservation>& reservations) {
	std::ifstream roomsfile("rooms.txt");

	if (roomsfile.is_open()) {
		std::string line;
		while (std::getline(roomsfile, line)) {
			std::stringstream ss(line);
			std::string field;
			Room r;

			// Get each field seperated by ";"
			// Rooms vector

			// Room number
			std::getline(ss, field, ';');
			r.roomNumber = std::stoi(field);

			// Room price
			std::getline(ss, field, ';');
			r.price = std::stod(field);

			// Reserved
			std::getline(ss, field, ';');
			r.reserved = std::stoi(field);

			// Capacity
			std::getline(ss, field, ';');
			r.capacity = std::stoi(field);

			rooms.push_back(r);
		}
		roomsfile.close();
	}

	std::ifstream reservationsfile("reservations.txt");

	if (reservationsfile.is_open()) {
		std::string line;
		while (std::getline(reservationsfile, line)) {
			std::stringstream ss(line);
			std::string field;
			Reservation res;

			// Get each field seperated by ";"
			// Reservations vector

			// Reservation number
			std::getline(ss, field, ';');
			res.reservationNumber = std::stoi(field);

			// Customer name
			std::getline(ss, field, ';');
			res.customer = field;

			// Discount percentage
			std::getline(ss, field, ';');
			res.discountPercentage = std::stod(field);

			// Bill
			std::getline(ss, field, ';');
			res.bill = std::stod(field);

			// Room number
			std::getline(ss, field, ';');
			res.roomNumber = std::stoi(field);

			// Capacity
			std::getline(ss, field, ';');
			res.capacity = stoi(field);

			// Duration
			std::getline(ss, field, ';');
			res.duration = std::stoi(field);

			reservations.push_back(res);
		}
		reservationsfile.close();
	}

	// For each reservation, mark the matching room as reserved and copy the reservation into it
	for (const auto& res : reservations) {
		int index = res.roomNumber - 1;
		if (index >= 0 && index < rooms.size()) {
			rooms[index].reserved = true;
			rooms[index].reservation = res;
		}
	}
	
}