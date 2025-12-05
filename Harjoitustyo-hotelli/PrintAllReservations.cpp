#include <iostream>
#include "header.h"

using std::cout;
using std::endl;
using std::to_string;

// Prints all reservations in order of creation
void PrintAllReservations(std::vector<Reservation> &reservations) {

	// Print error message if no reservations was found
	if (reservations.size() == 0) {
		std::cout << "\nThere isn't currently any active reservations in the system. " << endl;
	}
	// Print all reservations available
	else {
		std::cout << "\nAll booking details" << std::endl;
		for (int i = 0; i < reservations.size(); i++) {
			cout << endl << "-------------------------------------------" << endl;
			cout << "\nReservation " << i + 1 << endl;
			cout << endl << endl;

			PrintReservationField("Reservation number", to_string(reservations[i].reservationNumber));
			cout << endl;

			PrintReservationField("Room number", to_string(reservations[i].roomNumber));
			PrintReservationField("Room type", to_string(reservations[i].capacity) + " person room");
			cout << endl;

			PrintReservationField("Customer name",reservations[i].customer);
			PrintReservationField("Nights staying", to_string(reservations[i].duration));
			cout << endl;

			PrintReservationField("Discount percentage", to_string((int)(reservations[i].discountPercentage * 100)) + "%");
			PrintReservationField("Invoice", to_string((int)reservations[i].bill) + " euros");
			cout << endl;

		}
	}

}