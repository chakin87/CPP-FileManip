#ifndef CHRONOTIMER_HPP
#define	CHRONOTIMER_HPP
#include <chrono>
#include <string>
//#include <thread>
#include <iostream>
#include <fstream>

class ChronoTimer
{
public:
	ChronoTimer();// constructor 0
	//   Constructor 1 was made for a specific program I did in school. I made
	// this timing class to be barebones, so that you must tailor its use case
	// to the task at hand.
	ChronoTimer(int numOfFilesSorted);// constructor 1
	//    Constructor 2 is more of a general purpose type and weill be used in this program.
	ChronoTimer(std::string fileName, std::string title, std::string timingDescription, std::string  typeTimed, const int& numOfFilesSorted);// Constructor 2

	//   The destructor is very important. The timer is set and only stops once the 
	// ChonoTimer Object goes out of scope. I will implemnt more ways to use it, but
	// for now I have found that this method works well.
	//   Allocate a ChonoTimer on the stack and at the top of the scope that is
	// being timed. After the timed function ends, then end the scope and the 
	// ChonoTimer will stop immediately.
	~ChronoTimer();

public://methods
private://members
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	int constructorUsed, numFiles;
	std::string m_filename;
	std::string m_title;
	std::string m_description;
	std::string m_type;
};

#endif // !CHRONOTIMER_HPP