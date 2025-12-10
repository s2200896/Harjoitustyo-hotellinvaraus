#include <iostream>
#include "header.h"

void PrintBill(std::vector<Room>& rooms, int roomNumber, int nights, double bill) {
	// Print bill
	const int index = roomNumber - 1;	// Convert roomNumber to 0 based vector index
	double discountPercentage = rooms[index].reservation.discountPercentage;
	double initialPrice = rooms[index].price * nights;	// Before discount
	double discount = discountPercentage * initialPrice;	// Discount amount

	if (discount == 0.0) {
		std::cout << "\nTotal cost would be " << bill << " euros" << " from " << nights << " " << (nights == 1 ? "night" : "nights") << std::endl;
	}
	else {
		std::cout << "\nA " << discountPercentage * 100 << "% discount has been applied to your reservation. The discount totals " << discount <<
			" euros, resulting in a final price of " << bill << " euros for " << nights << " " << (nights == 1 ? "night" : "nights") << std::endl;
	}
}