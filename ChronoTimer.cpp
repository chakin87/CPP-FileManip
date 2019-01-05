#include "ChronoTimer.h"



ChronoTimer::ChronoTimer() :constructorUsed(0)
{
	start = std::chrono::high_resolution_clock::now();
}

ChronoTimer::ChronoTimer(int numOfFilesSorted) :
	constructorUsed(1), numFiles(numOfFilesSorted)
{
	start = std::chrono::high_resolution_clock::now();
}

ChronoTimer::ChronoTimer(std::string & fileName, std::string & title, std::string & timingDescription, const int & numOfFilesSorted) :
	constructorUsed(2), numFiles(numOfFilesSorted)
{
	//   Start the timer.
	start = std::chrono::high_resolution_clock::now();
}



ChronoTimer::~ChronoTimer()
{
	//   The timer is stopped before other process of the
	// destructor run, so that those processes are not
	// included in the timing.
	end = std::chrono::high_resolution_clock::now();

	if (constructorUsed == 0) {
		duration = end - start;
		std::cout <<"\n\n[" << duration.count() << " seconds]\n";
		std::cout << "[" << duration.count() * 1000 << " ms]\n";
		return;
	}
	else if (constructorUsed == 1) {
	//	end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		//std::cout << duration.count() << " seconds" << std::endl;
		//std::cout << duration.count() * 1000 << " ms" << std::endl;

		std::ofstream myFile("numbers.csv", std::ios::app);
		myFile << numFiles << "," << duration.count() * 1000 << std::endl;
		myFile.close();
		return;
	}
}

///void ChronoTimer::sleep(int secsToSleep)
//{
	//using namespace std::literals::chrono_literals;
	//std::this_thread::sleep_for(1s);
//}
