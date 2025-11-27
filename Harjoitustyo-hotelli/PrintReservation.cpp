#include "header.h"

// Prints the latest reservation made to the system
void PrintReservation(std::vector<Reservation> &reservations) {
	const Reservation& latest = reservations.back();
	std::cout << "Details of the latest booking" << std::endl;
	std::cout << "Name of the booker: " << latest.customer << std::endl;
	std::cout << "Reservation number: " << latest.reservationNumber << std::endl;
	std::cout << "Number of reserved room: " << latest.roomNumber << std::endl;
	
}