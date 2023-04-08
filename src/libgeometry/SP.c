#include <libgeometry/SP.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pi 3.14

double radius(char* str)
{
    char* strdata;
    str += 7;
    strtod(str, &strdata);
    str = strdata + 1;
    strtod(str, &strdata);
    str = strdata + 1;
    return strtod(str, &strdata);
}

int area(double r)
{
    int s = pi * r * r;
    return s;
}

int perimeter(double r)
{
    int p = 2 * pi * r;
    return p;
}

