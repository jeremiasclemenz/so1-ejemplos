// Listing 8.8 (better_sleep.c) High-Precision Sleep Function

/*
show EINTR using 
int nanosleep(const struct timespec *req, struct timespec *rem);
*/

#include <errno.h>
#include <time.h>

int better_sleep (double sleep_time)
{
 struct timespec tv;
 /* Construct the timespec from the number of whole seconds... */
 tv.tv_sec = (time_t) sleep_time;
 /* ... and the remainder in nanoseconds. */
 tv.tv_nsec = (long) ((sleep_time - tv.tv_sec) * 1e+9);

 while (1) {
    /* Sleep for the time specified in tv. If interrupted by a
      signal, place the remaining time left to sleep back into tv. 
    */
    int rval = nanosleep (&tv, &tv);
    
    if (rval == 0)
     /* Completed the entire sleep time; all done. */
     return 0;

    else if (errno == EINTR)
     /* Interrupted by a signal. Try again. */
     continue;
   
    else 
     /* Some other error; bail out. */
     return rval;
 }
 
 return 0;
}
