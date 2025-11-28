#include "header.h"

// Prints the latest reservation made to the system
void PrintReservation(std::vector<Reservation> &reservations) {
	const Reservation& latest = reservations.back();
	std::cout << "\nDetails of the latest booking" << std::endl;
	std::cout << "Name: " << latest.customer << std::endl;
	std::cout << "Reservation number: " << latest.reservationNumber << std::endl;
	std::cout << "Room: " << latest.roomNumber << std::endl;
	std::cout << "Room type: " << latest.capacity << " person room" << std::endl;
	
}