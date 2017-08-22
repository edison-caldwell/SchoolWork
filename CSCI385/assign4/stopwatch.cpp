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
	start = clock();
}

void StopWatch::Stop()
{
	stop = clock();
}

double StopWatch::GetTime()
{
	float total = 0; 

	total  = float(stop - start)/(CLOCKS_PER_SEC/1000);

	return total;
}

