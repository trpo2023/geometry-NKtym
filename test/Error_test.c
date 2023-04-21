#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/Error.h>

#include <ctest.h>

CTEST(TEST_circle_check, simple_circle)
{
    char* bad = "cirgle(0 0, 10)";
    char* good = "circle(0 0, 10)";
    int resultgood = circle_check(good);
    int resultbad = circle_check(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_open_bracket_check, simple_firstelement)
{
    char* bad = "CirCle 0 0, 10 1";
    char* good = "CirCle(0 0, 10)";
    int resultgood = open_bracket_check(good);
    int resultbad = open_bracket_check(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_arguments_check, simple_normalarg)
{
    char* bad = "CirCle(g 0, 10)";
    char* good = "CirCle(0 0, 10)";
    int resultgood = arguments_check(good);
    int resultbad = arguments_check(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_center_radius_check, simple_normalfloutnum)
{
    char* bad = "CirCle(0 0.6, 10.0.1.)";
    char* good = "CirCle(0 0, 10)";
    int resultgood = center_radius_check(good);
    int resultbad = center_radius_check(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_correct_number_check, simple_cntnum)
{
    char* bad = "CirCle(0 0 1, 10 5 )";
    char* good = "CirCle(0 0, 10)";
    int resultgood = correct_number_check(good);
    int resultbad = correct_number_check(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_comma_check, simple_delimiter)
{
    char* bad = "CirCle(0 0 10)";
    char* good = "CirCle(0 0, 10)";
    int resultgood = comma_check(good);
    int resultbad = comma_check(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_end, simple_endelement)
{
    char* bad = "CirCle(0 0, 10 1";
    char* good = "CirCle(0 0, 10)";
    int resultgood = close_bracket_check(good);
    int resultbad = close_bracket_check(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}
