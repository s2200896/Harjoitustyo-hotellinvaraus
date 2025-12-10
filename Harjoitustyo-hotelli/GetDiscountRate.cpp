#include <iostream>
#include "header.h"
#include <cstdlib>

// Generates a discount percentage of 0%, 10% or 20%
double GetDiscountRate() {
	double discount_rate = 0.0;
	int r = (std::rand() % 3) + 1;

	switch (r) {
		case 1: discount_rate;	// 0%
			break;
		case 2: discount_rate = 0.10;	// 10%
			break;
		case 3: discount_rate = 0.20;	// 20%
			break;
	}

	return discount_rate;
}