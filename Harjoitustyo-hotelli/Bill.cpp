#include <iostream>
#include "header.h"

// Returns the total hotel room bill, including any applicable discounts
double Bill(std::vector<Room>& rooms, int nights, int roomNumber, double discountPercentage) {
	const int index = roomNumber - 1;	// Convert roomNumber to 0 based vector index

	// Set nightly price by capacity
	if (rooms[index].capacity == 1) {
		rooms[index].price = 100.0;
	}
	else if(rooms[index].capacity == 2) {
		rooms[index].price = 150.0;
	}

	rooms[index].reservation.discountPercentage = discountPercentage;

	double initialPrice = rooms[index].price * nights;		// Before discount
	double discount = discountPercentage * initialPrice;	// Discount amount
	double reducedPrice = initialPrice - discount;		// After discount

	return reducedPrice;

}