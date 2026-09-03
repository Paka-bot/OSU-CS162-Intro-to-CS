#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class rectangle {
private:
	double width = 0; // Defaults to 0 if not set by constructor
	double height = 0; // Defaults to 0 if not set by constructor
public:
	// Default constructor. Does nothing, so width and height are defaulted
	// to zero (see above)
	rectangle();

	// Nondefault constructor. Sets width and height to given arguments.
	rectangle(double width, double height);

	// Getters / accessors
	double get_width() const;
	double get_height() const;

	// Mutators
	void set_width(double width);
	void set_height(double height);

	// Other member functions. In a good class design, most of your
	// functions will fall into this category. Only use getters and setters
	// when you feel like it's necessary.
	void print() const; // Prints rectangle's details
	double area() const; // Computes and returns rectangle's area
};

#endif
