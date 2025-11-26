#include "header.h"

// Returns the bill from the hotel room
// Add possible discounts later
double Bill(Room (&room), int nights, int roomNumber) {
    return nights * room.price;
}