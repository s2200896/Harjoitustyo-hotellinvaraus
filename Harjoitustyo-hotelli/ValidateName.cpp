#include <iostream>
#include "header.h"

bool ValidateName(const std::string& s) {
	// Locale for recognizing UTF-8 letters
	std::locale loc("fi_FI.utf8");

	if (s.empty()) {
		return false;
	}

	for (const char c : s) {
		if (c == ';') {
			return false;
		}
	}
	return true;
}