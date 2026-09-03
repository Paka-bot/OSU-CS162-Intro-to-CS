#ifndef SHOP_H
#define SHOP_H

class shop {
private:
	const float lemonade_price = 1.50;
	const float cookie_price = 2.00;

	int n_lemonades = 5;
	int n_cookies = 3;
	float todays_revenue = 0;
public:
	// Display's the shop's info to the terminal
	void display_info() const;

	// Purchases a lemonade (decreases number of
	// remaining lemonades, increases revenue)
	void buy_lemonade();

	// Purchases a cookie (decreases number of
	// remaining cookies, increases revenue)
	void buy_cookie();

	// Returns true if the shop is out of lemonades
	bool out_of_lemonades() const;

	// Returns true if the shop is out of cookies
	bool out_of_cookies() const;

	// Returns true if the shop is out of lemonades
	// and cookies
	bool out_of_stock() const;
};

#endif
