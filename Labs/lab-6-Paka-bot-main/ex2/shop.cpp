#include <iostream>
#include <iomanip>

#include "shop.hpp"

using namespace std;

void shop::display_info() const {
	std::cout << "--------------------------" << std::endl;
	std::cout << "Lemonades remaining: " << n_lemonades << std::endl;
	std::cout << "Cookies remaining: " << n_cookies << std::endl;
	std::cout << "Today's revenue: $" << fixed << setprecision(2)
		<< todays_revenue << std::endl;
	std::cout << "--------------------------" << std::endl;
}

void shop::buy_lemonade() {
	if (out_of_lemonades()) {
		std::cout << "Error! Lemonades are out of stock; "
			<< "cannot buy any more" << std::endl;
		return;
	}
	n_lemonades--;
	todays_revenue += lemonade_price;
}

void shop::buy_cookie() {
	if (out_of_cookies()) {
		std::cout << "Error! Cookies are out of stock; "
			<< "cannot buy any more" << std::endl;
		return;
	}
	n_cookies--;
	todays_revenue += cookie_price;
}

bool shop::out_of_lemonades() const {
	return n_lemonades <= 0;
}

bool shop::out_of_cookies() const {
	return n_cookies <= 0;
}

bool shop::out_of_stock() const {
	if (!out_of_lemonades() && !out_of_cookies()) {
		return false;
	} else {
		return true;
	}
}
