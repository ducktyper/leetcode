#include "helper.h"
#include "leetcode_018_4sum.c"

int assertFourSum(char * expected, char * input, int target);

int main()
{
    assert(assertFourSum("[[0,0,0,0]]", "[0,0,0,0]", 0));
    assert(assertFourSum("[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]", "[1,0,-1,0,-2,2]", 0));
    assert(assertFourSum("[[-5,-4,-3,1]]", "[1,-2,-5,-4,-3,3,3,5]", -11));
    assert(assertFourSum("[[-4,0,1,2],[-1,-1,0,1]]", "[-1,0,1,2,-1,-4]", -1));
}

int assertFourSum(char * expected, char * input, int target)
{
    int returnSize = 0;
    int numsSize;
    int * nums = stringToIntArray(input, &numsSize);
    int ** output = fourSum(nums, numsSize, target, &returnSize);

    char * actual = intArrayOfArrayToString(output, returnSize, 4);
    int status = 1;
    if (!assertString(expected, actual)) status = 0;

    for (int i = 0; i < returnSize; i++) free(output[i]);
    free(output);
    return status;
}
