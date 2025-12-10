#include <iostream>
#include "header.h"
#include "error_messages.h"

int SelectNights() {
	int nights;

	std::cout << "\nHow many nights would you like to reserve the room for?\n";

	// Validate amount of nights. Must be a number between 1 and 31
	do {
		validateType(nights, nights_errmsg);

		if (nights < 1 || nights > 31) {
			std::cout << nights_errmsg;
		}

	} while (nights < 1 || nights > 31);

	return nights;
}