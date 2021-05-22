
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "./../common_include.h"

// #define TIME_DIFFERENCE_IN_NANO_SEC

#if 0
#ifdef TIME_DIFFERENCE_IN_NANO_SEC
    static struct timespec
#else
    static struct timeval
#endif
    stop, start;

void SetTimer(void)
{
    #ifdef TIME_DIFFERENCE_IN_NANO_SEC
        clock_gettime(CLOCK_MONOTONIC, &start);
    #else
        gettimeofday(&start, NULL);
    #endif
}

void CheckDifference(const char * Str)
{
    unsigned long int diff = 0;

    #ifdef TIME_DIFFERENCE_IN_NANO_SEC
        clock_gettime(CLOCK_MONOTONIC, &stop);
    #else
        gettimeofday(&stop, NULL);
    #endif

    #ifdef TIME_DIFFERENCE_IN_NANO_SEC
        diff = (((stop.tv_sec - start.tv_sec) * 1000000000) + (stop.tv_nsec - start.tv_nsec));
    #else
        diff = ((stop.tv_sec - start.tv_sec) * 1000000) + (stop.tv_usec - start.tv_usec);
    #endif

    long seconds = (stop.tv_sec - start.tv_sec);
    long micros = ((seconds * 1000000) + stop.tv_usec) - (start.tv_usec);

    // char tTempStr[50]="";
    // sprintf(tTempStr, "%llu.%03llu", DiffmSec/1000, DiffmSec%1000);
    //if(DiffmSec > GetSysTmr(SYS_AUTO_REDIAL_TRK_DT_WAIT_TMR))
    {
        printf (" Diff");
        if(NULL != Str)         printf(" -<%s>", Str);
        #ifdef TIME_DIFFERENCE_IN_NANO_SEC
            printf(" nanoSec: %lu\n", diff);
        #else
            printf(" usec: %lu micros:%d\n", diff, micros);
        #endif
    }
}

#else

static struct timespec stime_stamp;

void SetTimer(void)
{
    if(0 != clock_gettime(CLOCK_MONOTONIC, &stime_stamp))
    {
        ERROR("Error while getting time of day");
    }
}

void CheckDifference(const char * Str)
{
    struct timespec ttime_stamp;
    if(0 != clock_gettime(CLOCK_MONOTONIC, &ttime_stamp))
    {
        ERROR("Error while getting time of day");
        return;
    }
    
    unsigned long int tCurTime=0, tPreTime=0;
    unsigned long int DiffmSec=0;
    
    tPreTime = ((unsigned long int)stime_stamp.tv_sec * (1000)) + ((unsigned long int)stime_stamp.tv_nsec / 1000000);
    tCurTime = ((unsigned long int)ttime_stamp.tv_sec * (1000)) + ((unsigned long int)ttime_stamp.tv_nsec / 1000000);
    
    if(tCurTime > tPreTime)     DiffmSec = tCurTime - tPreTime;
	else                        DiffmSec = tPreTime - tCurTime;
    
    stime_stamp = ttime_stamp;
    
    char tTempStr[50]="";
    sprintf(tTempStr, "%lu.%03lu", DiffmSec/1000, DiffmSec%1000);
    printf (" Diff");
    if(NULL != Str)         printf(" -<%s>", Str);
    printf(" Sec\t: %s2\n", tTempStr);    
}

#endif