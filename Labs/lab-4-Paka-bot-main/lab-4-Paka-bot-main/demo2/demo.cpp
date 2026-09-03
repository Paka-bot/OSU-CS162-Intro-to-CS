#include <iostream>
#include <fstream>

// Read input file name from user and return it.
std::string get_filename() {
	std::cout << "Enter file name: ";
	std::string filename;
	std::cin >> filename;
	return filename;
}

// Read n_names from top of input file. ifstreams MUST be passed by reference.
int get_n_names(std::ifstream& file) {
	int n_names;
	file >> n_names;
	return n_names;
}

// Write the given name to output.txt
void output_name_to_file(std::string name) {
	std::ofstream output_file;
	output_file.open("output.txt");
	output_file << name << std::endl;
}

int main() {
	std::string filename = get_filename();

	std::ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		// Failed to open file. Print error and end program.
		std::cout << "Error! Failed to open file." << std::endl;
	} else {
		// File exists and opened successfully. Continue with program.
		int n_names = get_n_names(file);

		// Create array of names and populate
		std::string* names = new std::string[n_names];
		for (int i = 0; i < n_names; i++) {
			file >> names[i];
		}

		// Write second name to output file
		output_name_to_file(names[1]);

		// Delete array of names
		delete [] names;
	}
}
