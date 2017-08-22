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

double StopWatch::Start()
{
	start = clock();
    
    return float(start)/(CLOCKS_PER_SEC/1000);
}

double StopWatch::Stop()
{
	stop = clock();
    
    return float(stop)/(CLOCKS_PER_SEC/1000);
}

double StopWatch::GetTime()
{
	float total = 0; 

	total  = float(stop - start)/(CLOCKS_PER_SEC/1000);

	return total;
}

