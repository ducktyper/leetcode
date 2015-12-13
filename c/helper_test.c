#include "helper.h"

int main()
{
    assertInt(1, 1);
    assertInt(1, 2);                      /* fail */

    assertDouble(2.0, 2.0);
    assertDouble(2.0, 2.1);               /* fail */

    assertString("aa", "aa");
    assertString("aa", "bb");             /* fail */

    int * array1 = stringToIntArray("[1,2,-3]");
    char * array1String = intArrayToString(array1, 3);
    assertIntArray(array1String, array1);
    assertIntArray("[1,2,-3,5]", array1); /* fail */
    free(array1);
    free(array1String);
}

