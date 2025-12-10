#include <iostream>
#include <iomanip>
#include "header.h"

void PrintReservationField(const std::string& label, const std::string& value, int width) {
	std::cout << std::left << std::setw(width) << label << ": " << value << std::endl;
}