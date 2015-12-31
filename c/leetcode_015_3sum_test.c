#include "helper.h"
#include "leetcode_015_3sum.c"

int assertThreeSum(char * expected, char * input);

int main()
{
    assert(assertThreeSum("[[0,0,0]]", "[0,0,0]"));
    assert(assertThreeSum("[]", "[0]"));
    assert(assertThreeSum("[[-1,0,1]]", "[1,0,-1]"));
    assert(assertThreeSum("[]", "[1,2,-2,-1]"));
    assert(assertThreeSum("[[-2,0,2],[-2,1,1]]", "[-2,0,1,1,2]"));
    assert(assertThreeSum("[[-1,0,1]]", "[1,-1,-1,0]"));
    assert(assertThreeSum("[[-2,-1,3],[-1,0,1],[0,0,0]]", "[-1,0,0,1,-2,3,0]"));
}

int assertThreeSum(char * expected, char * input)
{
    int returnSize = 0;
    int * nums = stringToIntArray(input);
    int numsSize = countArrayInString(input);
    int ** output = threeSum(nums, numsSize, &returnSize);

    char * actual = intArrayOfArrayToString(output, returnSize, 3);
    int status = 1;
    if (!assertString(expected, actual)) status = 0;

    for (int i = 0; i < returnSize; i++) free(output[i]);
    free(output);
    return status;
}
