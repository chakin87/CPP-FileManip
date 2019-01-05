#include <fstream>
#include <cstdlib>
//#include <ctime>
//#include <limits>
//#include <random>
//#include <string>

#include "ChronoTimer.h"
#include "StringPopulator.h"

int main(int argc, char** argv) {


	int n = 0, k = 1000;
	std::string name = "";
	char pause = 'c';

	while (pause == 'c'){
		ChronoTimer c;

		while (--k) {

			name = "";
			n = rand() % 14;
			name = StringPopulator::rand_lowercase_al_str(n);
			std::cout << "[name: " << name << " - n: " << n << "] | ";
		}

		//char pause[100];
		std::cin >> pause;
	}

	
	return 0;
}