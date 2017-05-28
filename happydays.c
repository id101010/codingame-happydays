/*
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 */

#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>

/* prototypes */
char *strptime(const char *s, const char *format, struct tm *tm);

/* data types */
typedef struct input_s {
    int leapYear;
    int sourceDayOfMonth;
    int targetDayOfMonth;
    char sourceDayOfWeek[9];
    char sourceMonth[4];
    char targetMonth[4];
} input_t;

/* debug function for the input string */
void debug_print(input_t *i)
{
    fprintf(stderr, "Leap: %d\n", i->leapYear);
    fprintf(stderr, "Source:\n DayOfWeek: %s\n Month: %s\n DayOfMonth: %d\n", i->sourceDayOfWeek, i->sourceMonth, i->sourceDayOfMonth);
    fprintf(stderr, "Target:\n Month: %s\n DayOfMonth: %d\n", i->targetMonth, i->targetDayOfMonth );
}

/* main function */
int main(int argc, char **argv)
{
    input_t in;
    struct tm source;
    struct tm target;

    /* Get values */
    scanf("%d", &(in.leapYear));
    scanf("%s%s%d", in.sourceDayOfWeek, in.sourceMonth, &(in.sourceDayOfMonth));
    scanf("%s%d", in.targetMonth, &(in.targetDayOfMonth));

    /* debug print */
    debug_print(&in);

    /* Convert input into a time struct */
    strptime(in.sourceDayOfWeek,"%a", &source);
    strptime(&in.sourceDayOfMonth,"%d", &source);
    strptime(in.sourceMonth, "%b", &source);
    mktime(&source);
    asctime(&source);

    exit(EXIT_SUCCESS);
}
