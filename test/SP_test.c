#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/SP.h>

#include <ctest.h>

CTEST(TEST_coordinatesx,simple_normalx)
{
    char* good = "circle(0.0 0.0, 10.0)";
    double resultgood = coordinatesx(good);
    ASSERT_DBL_NEAR(0.0, resultgood);
}

CTEST(TEST_coordinatesy,simple_normaly)
{
    char* good = "circle(0.0 0.0, 10.0)";
    double resultgood = coordinatesy(good);
    ASSERT_DBL_NEAR(0.0, resultgood);
}

CTEST(TEST_radius,simple_normalradius)
{
    char* good = "circle(0.0 0.0, 10.0)";
    double resultgood = radius(good);
    ASSERT_DBL_NEAR(10.0, resultgood);
}

CTEST(TEST_area,simple_correspondencearea)
{
    double good = 10;
    int resultgood = area(good);
    ASSERT_EQUAL(314, resultgood);
}

CTEST(TEST_perimeter,simple_correspondenceperimeter)
{
    double good = 10;
    int resultgood = perimeter(good);
    ASSERT_EQUAL(62, resultgood);
}

CTEST(TEST_intersection,simple_correspondenceintersection)
{
    circle* figur[3];
    circle* circle1 = (circle*)malloc(sizeof(circle1));
    circle* circle2 = (circle*)malloc(sizeof(circle2));
    circle* circle3 = (circle*)malloc(sizeof(circle3));
    circle1->r = 4;
    circle1->x = 1;
    circle1->y = 1;
    circle2->r = 4;
    circle2->x = 1;
    circle2->y = 1;
    circle3->r = 1;
    circle3->x = 10;
    circle3->y = 10;
    figur[0] = circle1;
    figur[1] = circle2;
    int resultgood=intersection(figur,2);
    figur[2] = circle3;
    int resultbad=intersection(figur,3);
    ASSERT_EQUAL(1, resultgood);
    ASSERT_EQUAL(0, resultbad);
}
