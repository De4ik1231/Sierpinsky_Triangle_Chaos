#include <time.h>
#include <stdio.h>

static struct timespec s_time; /* Структура для хранения стартового времени */
static struct timespec e_time; /* Структура для хранения времени завершения */

void start_time(void)
{
    clock_gettime(CLOCK_REALTIME, &s_time);
}



void end_time(void)
{
    int diff_sec; /* разница в секундах */
    int diff_nsec; /* разница в наносекундах */

    clock_gettime(CLOCK_REALTIME, &e_time);

    diff_sec = e_time.tv_sec - s_time.tv_sec;
    diff_nsec = e_time.tv_nsec - s_time.tv_nsec;

    if(diff_nsec < 0)
    {	    
        diff_sec--;	    
        diff_nsec = 10000000000 + diff_nsec;

    }	

    printf("%d cек  %d наносек\n", diff_sec, diff_nsec);
    
}

