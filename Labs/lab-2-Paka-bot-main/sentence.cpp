#include <iostream>
#include <string>

void get_sentence(std::string &s){
	std::cout << "Enter a sentence: ";
	// Note: getline() reads an entire line of text from the given
	// stream (std::cin, the terminal) and stores it in the given
	// string (s)
	getline(std::cin, s);
}

int main()
{
	std::string sentence;

	get_sentence(sentence);
	std::cout << sentence << std::endl;

	return 0;
}
