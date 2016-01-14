#include "helper.h"
#include "leetcode_027_remove_element.c"

int assertRemoveElement(char * expected, char * input, int val);

int main()
{
    assert(assertRemoveElement("[]", "[]", 1));
    assert(assertRemoveElement("[2,3]", "[1,2,3]", 1));
    assert(assertRemoveElement("[1,3]", "[1,2,2,3]", 2));
}

int assertRemoveElement(char * expected, char * input, int val)
{
    int count;
    int * nums = stringToIntArray(input, &count);

    int expectedCount;
    int * expectedNums = stringToIntArray(expected, &expectedCount);

    int status = 1;
    int actualCount = removeElement(nums, count, val);
    char * actualArray = intArrayToString(nums, actualCount);
    if (!assertString(expected, actualArray)) status = 0;
    if (!assertInt(expectedCount, actualCount)) status = 0;

    free(nums);
    free(expectedNums);
    free(actualArray);

    return status;
}
