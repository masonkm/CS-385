/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Kenneth Mason
 * Date        : 9/25/18
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System. kmason
 ******************************************************************************/
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool is_all_lowercase(const string &s) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
	for(unsigned int i = 0; i < s.size(); i++){
		if(!(islower(s[i]))){
			return false;
		}
	}
	return true;
}

bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
	unsigned int bit = 0;
	for(unsigned int i = 0; i < s.size(); i++){
		unsigned int temp = s[i] - 'a';

		if((bit >> temp) & 1){
			return false;
		}

		bit = (bit | (1 << temp));
	}
	return true;
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
	if (argc!=2) {
		cerr << "Usage: ./unique <string>" << endl;
	}
	else if (!(is_all_lowercase(argv[1]))) {
		cerr << "Error: String must contain only lowercase letters." << endl;
	}
	else if(all_unique_letters(argv[1])) {
		cout << "All letters are unique." << endl;
	} else {
		cout << "Duplicate letters found." << endl;
	}
}
