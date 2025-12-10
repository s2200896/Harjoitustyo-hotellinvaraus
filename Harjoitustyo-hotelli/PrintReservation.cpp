#include <iostream>
#include "header.h"

using std::cout;
using std::endl;
using std::to_string;

// Prints the latest reservation made to the system
void PrintReservation(std::vector<Reservation> &reservations) {

	// Print error message if no reservations was found
	if (reservations.size() == 0) {
		cout << "\nThere isn't currently any active reservations in the system. " << endl;
	}
	// Print the latest reservation in the system
	else {
		cout << "\nDetails of the latest booking" << endl;
		const Reservation& latest = reservations.back();
		cout << endl;
		PrintReservationField("Reservation number", to_string(latest.reservationNumber));
		cout << endl;

		PrintReservationField("Room number", to_string(latest.roomNumber));
		PrintReservationField("Room type", to_string(latest.capacity) + " person room");
		cout << endl;
		
		PrintReservationField("Customer name", latest.customer);
		PrintReservationField("Nights staying", to_string(latest.duration));
		cout << endl;

		PrintReservationField("Discount percentage", to_string((int)(latest.discountPercentage * 100)) + "%");
		PrintReservationField("Invoice", to_string((int)latest.bill) + " euros");
		cout << endl;

	}

}