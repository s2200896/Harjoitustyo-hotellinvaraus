#include <iostream>
#include "header.h"

using std::to_string;
using std::cout;
using std::endl;

void PrintResDetails(int roomNumber, int roomType, int nights, std::string customerName) {
	cout << "\nCurrent reservation details\n";
	cout << endl;
	PrintReservationField("Room", to_string(roomNumber));
	PrintReservationField("Room type", to_string(roomType) + " person room");
	cout << endl;
	PrintReservationField("Nights staying", to_string(nights));
	PrintReservationField("Name", customerName);

}