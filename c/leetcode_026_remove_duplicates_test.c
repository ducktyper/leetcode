#include "helper.h"
#include "leetcode_026_remove_duplicates.c"

int assertRemoveDuplicates(char * expected, char * input);

int main()
{
    assert(assertRemoveDuplicates("[]", "[]"));
    assert(assertRemoveDuplicates("[1,2,3]", "[1,2,3]"));
    assert(assertRemoveDuplicates("[1,2,3]", "[1,2,2,3]"));
}

int assertRemoveDuplicates(char * expected, char * input)
{
    int count;
    int * nums = stringToIntArray(input, &count);

    int expectedCount;
    int * expectedNums = stringToIntArray(expected, &expectedCount);

    int status = 1;
    int actualCount = removeDuplicates(nums, count);
    char * actualArray = intArrayToString(nums, actualCount);
    if (!assertString(expected, actualArray)) status = 0;
    if (!assertInt(expectedCount, actualCount)) status = 0;

    free(nums);
    free(expectedNums);
    free(actualArray);

    return status;
}
