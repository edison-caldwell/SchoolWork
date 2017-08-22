#include "stopwatch.h"

StopWatch::StopWatch()
{

}

StopWatch::StopWatch(const StopWatch& other)
{
	start = other.start;
	stop = other.stop;
}

StopWatch& StopWatch::operator=(const StopWatch& other)
{
	start = other.start;
	stop = other.stop;
}

void StopWatch::Start()
{
	time(&start);
}

void StopWatch::Stop()
{
	time(&stop);
}

int StopWatch::GetTime()
{
	int seconds = 0; 

	seconds = difftime(stop,start);

	return seconds;
}

