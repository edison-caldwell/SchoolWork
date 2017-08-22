#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <iostream>
#include <ctime>

using namespace std;

class StopWatch{
	
	public:
		StopWatch();
        //Default Constructor
        //Pre:
        //Post:
        
		StopWatch(const StopWatch& other);
		//Copy Constructor
        //Pre: 
        //Post: start and stop hold values of other.start and other.stop respectively
    
        StopWatch& operator=(const StopWatch& other);
        //Overloaded Assignment
        //Pre: 
        //Post: this and other are equivelent
        
		double Start();
        //Starts the timer
        //Pre:
        //Post: start holds the system time for when the function was called
        
		double Stop();
        //Stops the timer
        //Pre:
        //Post: stop holds the system time for when the funtion was called
        
		double GetTime();
        //Returns the difference of start and stop in seconds as an integer
        //Pre: Start and Stop have been called
        //Post: Returns the difference of start and stop

	private:
		clock_t start; //holds a timestamp of when Start() was called
		clock_t stop; //hold a timestamp of when Stop() was called
};


#endif
