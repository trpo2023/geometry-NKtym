#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/Error.h>

#include <ctest.h>

CTEST(TEST_figure, simple_circle)
{
    char* bad = "cirgle(0 0, 10)";
    char* good = "circle(0 0, 10)";
    int resultgood = figure(good);
    int resultbad = figure(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_first, simple_firstelement)
{
    char* bad = "CirCle 0 0, 10 1";
    char* good = "CirCle(0 0, 10)";
    int resultgood = first(good);
    int resultbad = first(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_arg, simple_normalarg)
{
    char* bad = "CirCle(g 0, 10)";
    char* good = "CirCle(0 0, 10)";
    int resultgood = arg(good);
    int resultbad = arg(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_flout, simple_normalfloutnum)
{
    char* bad = "CirCle(0 0, 10.0.1)";
    char* good = "CirCle(0 0, 10)";
    int resultgood = flout(good);
    int resultbad = flout(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_num, simple_cntnum)
{
    char* bad = "CirCle(0 0 1, 10 )";
    char* good = "CirCle(0 0, 10)";
    int resultgood = num(good);
    int resultbad = num(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_sumbol, simple_delimiter)
{
    char* bad = "CirCle(0 0 10)";
    char* good = "CirCle(0 0, 10)";
    int resultgood = sumbol(good);
    int resultbad = sumbol(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}

CTEST(TEST_end, simple_endelement)
{
    char* bad = "CirCle(0 0, 10 1";
    char* good = "CirCle(0 0, 10)";
    int resultgood = end(good);
    int resultbad = end(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}
