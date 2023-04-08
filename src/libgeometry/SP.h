#include <stdio.h>

typedef struct circle
{
    double x;
    double y;
    double r;
} circle;

double radius(char* str);
int area(double r);
int perimeter(double r);
