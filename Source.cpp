#include <fstream>
#include <cstdlib>
#include <cstdio>
//#include <ctime>
//#include <limits>
//#include <random>
//#include <string>

#include "ChronoTimer.h"
#include "StringPopulator.h"

	std::string names[1000000];
int main(int argc, char** argv) {

	int n = 0, k = 1000000;
	int j = k;
	std::string name = "";

	for (int i = 0,z=0; i < j; ++i,++z) {
		name = "";
		n = rand() % 14;
		name = StringPopulator::rand_lowercase_al_str(n);
		names[i] = name;
		if (z == 3000) {
			system("CLS");
			printf("Populating names[]   |");
		}
		else if (z == 6000) {
			system("CLS");
			printf("Populating names[]   /");
		}
		else if (z == 9000) {
			system("CLS");
			printf("Populating names[]   --");
		}
		else if (z == 12000) {
			system("CLS");
			printf("Populating names[]   \\");
			z = 0;
		}
	}
	
	{
		ChronoTimer c("coutvsprintf.csv", "Cout vs Printf", "using printf()", "console output speed", j);
		for (int i = 0; i < j; ++i) {
			printf("[Name: %s](n: %d)\n", names[i].c_str(), i);
		}
	}	

	{
		ChronoTimer c("coutvsprintf.csv", "Cout vs Printf", "using cout", "console output speed", j);
		for (int i = 0; i < j; ++i) {
			std::cout << "[Name: " << names[i] << "](n: " << i << ")\n";
		}		
	}

	
	char pause[10];
	std::cin >> pause;
	
	return 0;
}