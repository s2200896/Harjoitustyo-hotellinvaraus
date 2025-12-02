#include <iostream>
#include "header.h"

bool ValidateName(const std::string& s) {
	// Locale for recognizing UTF-8 letters
	std::locale loc("fi_FI.utf8");

	// Allow letters, spaces and "-"
	for (const char c : s) {
		if (!isalpha(c) && !isspace(c) && c != '-') {
			return false;
		}
	}
	return true;
}