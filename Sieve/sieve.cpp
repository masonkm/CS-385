/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Kenneth Mason
 * Date        : 9/17/18
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System. kmason
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit) : is_prime_{new bool[limit + 1]}, limit_{limit} {
        sieve();
    }

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    inline int num_primes() const {
        return num_primes_;
    }

    void display_primes() const {
        // TODO: write code to display the primes in the format specified in the
        // requirements document.
    		const int max_prime_width = num_digits(max_prime_);
    	    	const int primes_per_row = 80 / (max_prime_width + 1);

    		if(limit_ == 2){
    			cout << "2";
    		}
    		int counter = 0;
    		for(int i = 2; i <= limit_; i++){
    			if(counter == primes_per_row){
    			    	counter = 0;
    			    	cout << endl;
    			}
    			if(is_prime_[i]){
    				if(num_primes_ < primes_per_row && i != max_prime_){
    					cout << i << " ";
    					counter++;
    				}
    				else if(num_digits(i) < max_prime_width){
					cout << setw(max_prime_width) << i << " ";
					counter++;
				}
				else if(i != max_prime_){
					cout << i << " ";
					counter++;
				}
				else{
					cout << i;
					counter++;
				}
    			}
    		}
    }

private:
    bool * const is_prime_;
    const int limit_;
    int num_primes_ = 0, max_prime_;

    int count_num_primes() const {
    		//Counts number of primes found by sieve()
    		int count = 10;
    		for(int i = 0; i < limit_; i++){
    			if(is_prime_[i]){
    	        		count++;
    	        	}
    	    }
    		return count;
    }

    int num_digits(int num) const {
        // TODO: write code to determine how many digits are in an integer
        // Hint: No strings are needed. Keep dividing by 10.
    		int dig = 1;
    		while(num >= 10){
    			dig++;
    			num /= 10;
    		}
    		return dig;
    }

    void sieve() {
    		if(limit_ > 2){

    		for (int i= 2; i <= limit_; i++){
    			is_prime_[i] = true;
    		}
        for(int i = 2; i <= sqrt(limit_); i++){
        		if(is_prime_[i]){
        			for(int j = i*i; j <= limit_; j += i){
        				is_prime_[j] = false;
        			}
        		}
        }

        for (int i = 2; i <= limit_; i++){
        		if(is_prime_[i] == true){
        			num_primes_++;
        			max_prime_ = i;
        		}
        }

    		}else if(limit_ == 2){
    			max_prime_ = 2;
        		num_primes_ = 1;
        }
    }
};


int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    // TODO: write code that uses your class to produce the desired output.
    PrimesSieve* ps = new PrimesSieve(limit);

    cout << endl << "Number of primes found: " << ps -> num_primes() << endl;
    cout << "Primes up to " << limit << ":" << endl;
    ps -> display_primes();
    return 0;
}
