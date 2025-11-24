#include "header.h"

// Returns the bill from the hotel room
double Bill(Room& hotel, int nights) {
	return nights * hotel.price;
}