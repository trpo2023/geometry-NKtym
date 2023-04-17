#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/Error.h>

#include <ctest.h>

/*CTEST(TEST_figure,simple_circle)
{
    char* bad = "rwgJFKFK";
    char* good = "CirCle";
    int resultgood = figure(good);
    int resultbad = figure(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}
*/
CTEST(TEST_first,simple_firstelement)
{
    char* bad = "rwgJFKFK";
    char* good = "CirCle(0 0, 10)";
    int resultgood = first(good);
    int resultbad = first(bad);
    ASSERT_EQUAL(1, resultbad);
    ASSERT_EQUAL(0, resultgood);
}
