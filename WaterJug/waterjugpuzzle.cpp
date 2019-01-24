/*
 * waterjugpuzzle.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: Kenneth Mason and Anthony Ciccone
 *      I pledge my honor that I have abided by the Stevens Honor System. aciccone kmason
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

vector<string> outVector;

// Struct to represent state of water in the jugs.
struct State {
    int a, b, c;
    vector<string> directions;
    vector<State> parent;

    State(int _a, int _b, int _c) : a(_a), b(_b), c(_c) { }

    // String representation of state in tuple form.
    string to_string() {
        ostringstream oss;
        oss << "(" << a << ", " << b << ", " << c << ")";
        return oss.str();
    }
};

// Method for searching through all the possibilities and finding the water jug solution
vector<string> bfs(State start, State end, int a_cap, int b_cap, int c_cap){
	string out;
	bool **visited = new bool*[a_cap + 1];
	for(int i = 0; i < a_cap + 1; ++i){
		visited[i] = new bool[b_cap + 1];
		for(int j = 0; j < b_cap + 1; ++j){
			visited[i][j] = false;
		}
	}
	State accept(-1, -1, -1);
	queue<State> q;
	start.directions.push_back("Initial state. " + start.to_string());
	visited[start.a][start.b] = true;
	q.push(start);
	while(!q.empty()){
		State root = q.front();
		if(root.a == end.a && root.b == end.b && root.c == end.c){
			accept.a = end.a;
			accept.b = end.b;
			accept.c = end.c;
			break;
		}

	//Seeing if we can move from B to A
		if(root.a < a_cap && root.b != 0){
			int move;
			if(root.a + root.b > a_cap){
				move = a_cap - root.a;
			}else{
				move = root.b;
			}
			if(!visited[root.a + move][root.b - move]){
				visited[root.a + move][root.b - move] = true;
				State temp(root.a + move, root.b - move, root.c);
				temp.parent.push_back(root);
				string output;
				if(move == 1){
					output = "Pour 1 gallon from B to A. " + temp.to_string();
				}else{
					output = "Pour " + to_string(move) + " gallons from B to A. " + temp.to_string();
				}
				temp.directions.push_back(output);
				q.push(temp);
			}
		}

	//Seeing if we can move from C to B
		if(root.b < b_cap && root.c != 0){
			int move;
			if(root.c + root.b > b_cap){
				move = b_cap - root.b;
			}else{
				move = root.c;
			}
			if(!visited[root.a][root.b + move]){
				visited[root.a][root.b + move] = true;
				State temp(root.a, root.b + move, root.c - move);
				temp.parent.push_back(root);
				string output;
				if(move == 1){
					output = "Pour 1 gallon from C to B. " + temp.to_string();
				}else{
					output = "Pour " + to_string(move) + " gallons from C to B. " + temp.to_string();
				}
				temp.directions.push_back(output);
				q.push(temp);
			}
		}

	//Seeing if we can move from C to A
		if(root.a < a_cap && root.c != 0){
			int move;
			if(root.a + root.c > a_cap){
				move = a_cap - root.a;
			}else{
				move = root.c;
			}
			if(!visited[root.a + move][root.b]){
				visited[root.a + move][root.b] = true;
				State temp(root.a + move, root.b, root.c - move);
				temp.parent.push_back(root);
				string output;
				if(move == 1){
					output = "Pour 1 gallon from C to A. " + temp.to_string();
				}else{
					output = "Pour " + to_string(move) + " gallons from C to A. " + temp.to_string();
				}
				temp.directions.push_back(output);
				q.push(temp);
			}
		}

	//Seeing if we can move from B to C
		if(root.c < c_cap && root.b != 0){
			int move;
			if(root.b + root.c > c_cap){
				move = c_cap - root.c;
			}else{
				move = root.b;
			}
			if(!visited[root.a][root.b - move]){
				visited[root.a][root.b - move] = true;
				State temp(root.a, root.b - move, root.c + move);
				temp.parent.push_back(root);
				string output;
				if(move == 1){
					output = "Pour 1 gallon from B to C. " + temp.to_string();
				}else{
					output = "Pour " + to_string(move) + " gallons from B to C. " + temp.to_string();
				}
				temp.directions.push_back(output);
				q.push(temp);
			}
		}

	//Seeing if we can move from A to B
		if(root.b < b_cap && root.a != 0){
			int move;
			if(root.a + root.b > b_cap){
				move = b_cap - root.b;
			}else{
				move = root.a;
			}
			if(!visited[root.a - move][root.b + move]){
				visited[root.a - move][root.b + move] = true;
				State temp(root.a - move, root.b + move, root.c);
				temp.parent.push_back(root);
				string output;
				if(move == 1){
					output = "Pour 1 gallon from A to B. " + temp.to_string();
				}else{
					output = "Pour " + to_string(move) + " gallons from A to B. " + temp.to_string();
				}
				temp.directions.push_back(output);
				q.push(temp);
			}
		}

	//Seeing if we can move from A to C
		if(root.c < c_cap && root.a != 0){
			int move;
			if(root.a + root.c > c_cap){
				move = c_cap - root.c;
			}else{
				move = root.a;
			}
			if(!visited[root.a - move][root.b]){
				visited[root.a - move][root.b] = true;
				State temp(root.a - move, root.b, root.c + move);
				temp.parent.push_back(root);
				string output;
				if(move == 1){
					output = "Pour 1 gallon from A to C. " + temp.to_string();
				}else{
					output = "Pour " + to_string(move) + " gallons from A to C. " + temp.to_string();
				}
				temp.directions.push_back(output);
				q.push(temp);
			}
		}
		q.pop();
	}
	//Adding everything to the 'out' string which is our final string we return
	if(accept.a == -1 && accept.b == -1 && accept.c == -1){
		outVector.push_back("No solution.\n");
	}else{
		State temp = q.front();
		outVector.push_back(temp.directions[0] + "\n");
		while(!temp.parent.empty()){
			temp = temp.parent[0];
			outVector.push_back(temp.directions[0] + "\n");
		}
	}

	//Cleaning up the memory
	for(int i = 0; i < a_cap + 1; ++i){
		delete [] visited[i];
	}
	delete [] visited;
	return outVector;
}


int main(int argc, char * argv[]) {
	int args[] = {0,0,0,0,0,0};
	if(argc != 7){
		cerr << "Usage: " << argv[0] << " <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << endl;
		return 1;
	}
	string jugs[] = {"A", "B", "C"};
	istringstream iss;
	for(int i = 0; i < argc - 1; i++){
		iss.str(argv[i + 1]);
		if(!(iss>>args[i])){
			if(i < 3){
				cerr << "Error: Invalid capacity '" << argv[i + 1] << "' for jug " << jugs[i] << ".";
				return 1;
			}else{
				cerr << "Error: Invalid goal '" << argv[i + 1] << "' for jug " << jugs[i - 3] << ".";
				return 1;
			}
		}
		if(args[i] < 1){
			if(i < 3){
				cerr << "Error: Invalid capacity '" << argv[i + 1] << "' for jug " << jugs[i] << ".";
				return 1;
			}else if(args[i]<0){
				cerr << "Error: Invalid goal '" << argv[i + 1] << "' for jug " << jugs[i - 3] << ".";
				return 1;
			}
		}
		iss.clear();
	}
	for(int i = 0; i < 3; i++){
		if(args[i+3] > args[i]){
			cerr << "Error: Goal cannot exceed capacity of jug " << jugs[i%3] << ".";
			return 1;
		}
	}
	if(args[2] != (args[3]+args[4]+args[5])){
		cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C.";
		return 1;
	}
	State start(0, 0, args[2]);
	State end(args[3], args[4], args[5]);
	vector<string> bfsVector = bfs(start, end, args[0], args[1], args[2]);
	for(unsigned int i = bfsVector.size(); i > 0; i--){
		cout << bfsVector[i-1];
	}
	return 0;
}










