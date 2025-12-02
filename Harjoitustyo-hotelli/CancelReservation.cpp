#include <iostream>
#include "header.h"
#include "error_messages.h"

static int findRoomIndex(const std::vector<Room>& rooms, int reservationNumber);
static int findReservationIndex(const std::vector<Reservation>& reservations, int reservationNumber);

// Cancel reservation associated with the given reservation number
void CancelReservation(std::vector<Room>& rooms, std::vector<Reservation>& reservations) {
	int reservationNumber;

	std::cout << "Enter a reservation number: ";

	// Validate reservation number
	do {
		validateType(reservationNumber, reservationNumber_errmsg);

		if (reservationNumber < 1) {
			std::cout << reservationNumber_errmsg;
		}

	} while (reservationNumber < 1);

	// Check if the given number matches any reservation
	int RoomIndex = findRoomIndex(rooms, reservationNumber);
	int ReservationIndex = findReservationIndex(reservations, reservationNumber);

	// Reservation was found
	if (ReservationIndex != -1) {
		int choice;
		const int i = ReservationIndex;
		const int j = RoomIndex;

		std::cout << "\nThe following booking was found" << std::endl;
		std::cout << "\Name: " << reservations[i].customer << std::endl;
		std::cout << "Reservation number: " << reservations[i].reservationNumber << std::endl;
		std::cout << "Room: " << reservations[i].roomNumber << std::endl;
		std::cout << "Room type: " << reservations[i].capacity << std::endl;

		std::cout << "\nCancel the reservation? Yes [1], No [0]" << std::endl;

		// Validate input
		do {
			validateType(choice, choice_errmsg);

			if (choice != 1 && choice != 0) {
				std::cout << choice_errmsg;
			}

		} while (choice != 1 && choice != 0);

		// Cancel reservation
		if (choice == 1) {

			// Clear room
			rooms[j].reservation.reservationNumber = 0;
			rooms[j].reserved = false;
			rooms[j].reservation.customer = "";

			// Delete reservation from reservations vector
			reservations.erase(reservations.begin() + i);

			std::cout << "\nReservation is cancelled." << std::endl;
		}

	}
	// Reservation not found
	else {
		int selection;

		std::cout << "\nNo reservation was found." << std::endl;
		std::cout << "\nWould you like to try another reservation number? Yes [1], No [0]" << std::endl;

		// Validate input
		do {
			validateType(selection, choice_errmsg);

			if (selection != 1 && selection != 0) {
				std::cout << choice_errmsg;
			}

		} while (selection != 1 && selection != 0);

		// Try with another reservation number
		if (selection == 1) {
			CancelReservation(rooms, reservations);
		}

	}


}

// Return correct index or -1 if not found
static int findRoomIndex(const std::vector<Room>& rooms, int reservationNumber) {
	
	// Search for room with the given reservation number
	for (int i = 0; i < rooms.size(); i++) {
		if (rooms[i].reservation.reservationNumber == reservationNumber) {
			return i;
		}
	}
	// Not found
	return -1;
}

// Return correct index or -1 if not found
static int findReservationIndex(const std::vector<Reservation>& reservations, int reservationNumber) {

	// Search for reservation with given reservation number
	for (int i = 0; i < reservations.size(); i++) {
		if (reservations[i].reservationNumber == reservationNumber) {
			return i;
		}
	}
	// Not found
	return -1;
}