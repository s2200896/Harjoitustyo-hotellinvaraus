#include <iostream>
#include "header.h"
#include "error_messages.h"

void SelectName(std::string & customerName) {
	int confirm;

	// Ask customer's name
	do {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		do {
			std::cout << "\nIn whose name the reservation is made? (first and last name)\n";
			std::getline(std::cin, customerName);

			if (!ValidateName(customerName)) {
				std::cout << "\nInvalid input. Please enter first and last name again." << std::endl;
			}

		} while (!ValidateName(customerName));

		std::cout << "\nIs the following name correct: " << customerName << std::endl << "Yes[1], No[0]: ";

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
}