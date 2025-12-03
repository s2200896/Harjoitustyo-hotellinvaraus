#include <iostream>
#include <fstream>
#include "header.h"

// Save current room and reservation data to disk
void RoomDataToFile(std::vector<Room>& rooms, std::vector<Reservation>& reservations) {

	// Write contents of the room vector to a file
	std::ofstream roomsfile ("rooms.txt");

	if (roomsfile.is_open()) {
		// Write each room's data to the file, fields separated by semicolon
		for (auto& element : rooms) {
			roomsfile << element.roomNumber << ";" <<
				element.price << ";" << element.reserved << ";" <<
				element.capacity << ";" << std::endl;
		}

		roomsfile.close();
	}


	// Write contents of the reservation vector to a file
	std::ofstream reservationsfile ("reservations.txt");

	if (reservationsfile.is_open()) {
		// Write each reservation to the file, fields separated by semicolon
		for (auto& element : reservations) {
			reservationsfile << element.reservationNumber << ";" <<
				element.customer << ";" <<
				element.discountPercentage << ";" <<
				element.bill << ";" <<
				element.roomNumber << ";" <<
				element.capacity << ";" << 
				element.duration << ";" << std::endl;
		}

		reservationsfile.close();
	}
}