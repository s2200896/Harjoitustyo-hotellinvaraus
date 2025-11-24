#include <iostream>
#include <limits>
#include <string>



// Room structure
struct Room
{
	static const int quantity = 10;		// Total number of rooms
	double price = 100.0;				// Default price for a room
	int roomStatus[quantity] = { 0 };	// Initialize with 0, 0 = empty room, 1 = reserved room
	int reservationNumber;

};

struct Reservation
{
	int reservationNumber;
	std::string customerName;
};

// Function declarations
void ReserveRoom(Room& hotel);
double Bill(Room& hotel, int nights);
bool IsRoomEmpty(const Room& room, int);
template <typename T> void validateType(T& input, const std::string errMsg);


// Error messages, move to .h later
const std::string room_errmsg = "Invalid room number. Please enter a number between 1 and 10: ";
const std::string nights_errmsg = "Invalid amount of nights. Please enter a positive number: ";
const std::string choice_errmsg = "Invalid input. Please enter [1] for Yes, [0] for No:  ";
const std::string common_errmsg = "Unfortunately I can't help you with that. Please select an option from the list: ";


int main() {
	int input;
	int choice;
	Room hotel;		// Stores reservation data 
	Reservation reservation;



	do {

		std::cout << "How may I help you?" << std::endl;
		std::cout << "1. Reserve Room" << std::endl;

		// Validate menu input
		do {
			validateType(input, common_errmsg);
			if (input != 1) {	// Change condition as the functionality expands
				std::cout << common_errmsg;
			}

		} while (input != 1);



		// Handle selected menu option
		switch (input) {
		case 1: ReserveRoom(hotel);
			break;
			// Add more options later
		
		}

		// Make sure that there isn't any leftover characters before using cin.get()
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Ask customer if they want to continue
		std::cout << "\nCan I help you with something else? Yes [1], No [0]" << std::endl;

		// Validate input
		do {
			validateType(choice, choice_errmsg);
			if (choice != 1 && choice != 0) {
				std::cout << choice_errmsg;
			}

		} while (choice != 1 && choice != 0);


		// Greet the customer

	} while (choice == 1);
	

	return 0;
}



void ReserveRoom(Room& hotel){
	int roomNumber;
	bool empty;
	int nights; 
	double bill;
	int choice;
	int confirm;
	Reservation reservation;


	do {

		std::cout << "What room would you like to reserve? (1-10):\n";

		// Validate room number. Must be integer, more or equal to 1 and less or equal to hotel.quantity (total amount of rooms)
		do {
			validateType(roomNumber, room_errmsg);

			if (roomNumber < 1 || roomNumber > hotel.quantity) {
				std::cout << room_errmsg;
			}

		} while (roomNumber < 1 || roomNumber > hotel.quantity);



		// Store information about the reservation to variable
		empty = IsRoomEmpty(hotel, roomNumber);



		// Reserve room if empty
		if (empty) {
			// Add functionality to store the information about reservation

			std::cout << "How many nights would you like to reserve the room for?\n";

			// Validate amount of nights. Must be integer and positive number.
			do {
				validateType(nights, nights_errmsg);

				if (nights < 1) {
					std::cout << nights_errmsg;
				}

			} while (nights < 1); // Max value for amount of nights is not defined


			// Ask customer's name
			// TODO: Link customer to the room being reserved
			do {
				std::cout << "In whose name the reservation is made? (first and last name)\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, reservation.customerName);

				std::cout << "Is the following name correct: " << reservation.customerName << std::endl << "Yes[1], No[0]: ";

				// Validate input. Must be 1 or 0
				do {
					validateType(confirm, choice_errmsg);

					if (confirm != 1 && confirm != 0) {
						std::cout << choice_errmsg;
					}
				} while (confirm != 1 && confirm != 0);

				// If name is correct break
				if (confirm == 1) {
					break;
				}

			} while (confirm == 0);		// If name is incorrect, ask customer to enter it again



			bill = Bill(hotel, nights);		// Store bill information in variable

			std::cout << "Total cost would be " << bill << " Euros" << " from " << nights << " nights\n";	 // Condition for whether to print "night" or "nights"?	

			std::cout << "Confirm reservation? Yes [1], No [0]\n";
			
			// Validate input. Must be 1 or 0
			do {
				validateType(choice, choice_errmsg);

				if (choice != 1 && choice != 0) {
					std::cout << choice_errmsg;
				}

			} while (choice != 1 && choice != 0);

		

			if (choice == 1) {
				std::cout << "Room " << roomNumber << " reserved.\n";
				hotel.roomStatus[roomNumber - 1] = 1; // Reserve room

			}
			else {
				ReserveRoom(hotel);		// Start over incase of cancelled reservation 
			}
		}
		else {
			std::cout << "Room " << roomNumber << " is already reserved. Please select another room.\n";
		}

	} while (!empty);	//	Ask customer to select other room if reserved


}


// Returns the bill from the hotel room
double Bill(Room& hotel, int nights) {
	return nights * hotel.price;
}


// Returns 1, if empty
bool IsRoomEmpty(const Room& room, int roomNumber) {
	return room.roomStatus[roomNumber - 1] == 0;
	
}



// Continously reads input into "input" until a valid value of type T is entered 
// if the extraction fails customer will be prompted with the provided error message
template <typename T> void validateType(T& input, const std::string errMsg) {

	std::cin >> input;

	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << errMsg;

		std::cin >> input;
	}

}