/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Kenneth Mason
 * Date        : 10/1/18
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System. Kenneth Mason
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector<vector<int>> ways;
vector<int> currentWay;
stringstream ss;

vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
	if(num_stairs <= 0){
		ways.push_back(currentWay);
	}
	if(num_stairs >= 1){
		currentWay.push_back(1);
		get_ways(num_stairs-1);
	}
	if(num_stairs >= 2){
		currentWay.push_back(2);
		get_ways(num_stairs-2);
	}
	if(num_stairs >= 3){
		currentWay.push_back(3);
		get_ways(num_stairs-3);
	}
	currentWay.pop_back();
	return ways;


}

int num_digits(int num){
    // Determines how many digits are in an integer
    	int dig = 1;
	while(num >= 10){
    		dig++;
   		num /= 10;
    	}
    	return dig;
}

string displ_vect(const vector<int> way){
	// Returns a string representation of a single vector<int>
	string str = "[";
	unsigned int i = 0;
	for(auto it = way.begin(); it != way.end(); it++){
		ss << way[i];
		if(i != way.size()-1){
			str += ss.str() + ", ";
		}else{
			str += ss.str() + "]";
		}
		ss.str("");
		i++;
	}
	return str;
}

void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.

	int i = ways.size();
	int maxdig = num_digits(i);

	for(int j = 0; j < i; j++){
		cout << setw(maxdig) << j+1 << ". " << displ_vect(ways[j]) << endl;
	}
}

int main(int argc, char * const argv[]) {
	if (argc != 2) {
		cout << "Usage: ./stairclimber <number of stairs>" << endl;
		return 1;
	}

	istringstream iss(argv[1]);
	int num_stairs;

	if (!(iss >> num_stairs) || num_stairs < 0) {
		cout << "Error: Number of stairs must be a positive integer." << endl;
		return 1;
	}

	int waySize = get_ways(num_stairs).size();
	if (waySize == 1) {
	cout << "1 way to climb 1 stair." << endl;
	} else {
		cout << waySize << " ways to climb " << num_stairs << " stairs." << endl;
	}

	ways.clear();
	currentWay.clear();
	ss.str("");

	display_ways(get_ways(num_stairs));
	return 0;
}





