#include "/courses/COMPX203/ex2/lib_ex2.h"
#define MIN 0
#define MAX 1000

/**
 * count(int start, int end)
 * 
 * Counts from 'start' to 'end' (inclusive), and shows the progress on
 * the SSDs. Checks if a value passed in is within an appropriate range,
 * or else sets it to the defined MIN or MAX value. 
 **/
void count(int start, int end) {
   
    /**
     * Declares int variables to use for counting, and sets them to the 
     * absolute values which are passed in, so that -1 < n.
     **/
    int s = abs(start); 
    int e = abs(end); 

    /**
     * Checks if the new values are n < 1000, or else sets the variables 
     * to the appropriate MIN or MAX value. Note that 's' may not
     * take the MAX value, so to maintain a difference if found equal.
     **/
    (s < MAX) ? (s = s) : (s = MIN); 
    (e <= MAX) ? (e = e) : (e = MAX); 
    (s == e) ? (e = MAX) : (e = e);
    
    /**
     * Declares new variables for the count, and finds the difference
     * to use as a limit for the counter 'i', then sets the start of the
     * count 'a' to the lesser value in the range.
     **/
    int a = 0;
    int i = 0;
    int diff = abs(e - s); 
    (s > e) ? (a = e) : (a = s);

    /**
     * Loops until the difference is reached, calls writessd(a) to write
     * the first value to the display, then iterates up or down depending
     * on the direction of the count. 
     **/
    while(i < diff){     
        writessd(a);
        (s > e) ? (a--) : (a++);
        delay();
        i++;
    }
    return;
}