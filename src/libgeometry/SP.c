#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/SP.h>

#define _USE_MATH_DEFINES

double coordinatesx(char* str)
{
    char* strdata;
    str += 7;
    return strtod(str, &strdata);
}

double coordinatesy(char* str)
{
    char* strdata;
    str += 7;
    strtod(str, &strdata);
    str = strdata + 1;
    return strtod(str, &strdata);
}

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
    int s = M_PI * r * r;
    return s;
}

int perimeter(double r)
{
    int p = 2 * M_PI * r;
    return p;
}

int intersection(circle** figur, long unsigned int n)
{
    int flag = 0;
    double distancex, distancey, sumradius;
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i; j < n; j++) {
            distancex = (figur[i]->x) - (figur[j]->x);
            distancey = (figur[i]->y) - (figur[j]->y);
            sumradius = (figur[i]->r) + (figur[j]->r);
            if (distancex < 0) {
                distancex *= -1;
            }
            if (distancey < 0) {
                distancey *= -1;
            }
            if ((sumradius > distancex) && (sumradius > distancey)) {
                flag = 1;
            } else {
                flag = 0;
                return flag;
            }
        }
    }
    return flag;
}
