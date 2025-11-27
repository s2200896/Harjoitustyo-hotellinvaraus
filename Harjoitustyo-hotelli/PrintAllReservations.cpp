#include <iostream>
#include "header.h"

// Prints all reservations in order of creation
void PrintAllReservations(std::vector<Reservation> &reservations) {

	std::cout << "\nAll booking details" << std::endl;
	for (int i = 0; i < reservations.size(); i++) {
		std::cout << "\nReservation " << i + 1 << std::endl;
		std::cout << "\nName of the booker: " << reservations[i].customer << std::endl;
		std::cout << "Reservation number: " << reservations[i].reservationNumber << std::endl;
		std::cout << "Number of the room reserved: " << reservations[i].roomNumber << std::endl;
	}

}