#pragma once

typedef struct circle {
    double x;
    double y;
    double r;
} circle;

double coordinatesx(char* str);
double coordinatesy(char* str);
double radius(char* str);
int area(double r);
int perimeter(double r);
int intersection(circle** figur, long unsigned int n);
