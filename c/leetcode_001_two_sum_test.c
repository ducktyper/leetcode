#include "helper.h"
#include  "leetcode_001_two_sum.c"

int assertTwoSum(char * expect, char * array, int target);

int main()
{
    assert(assertTwoSum("[1,2]", "[5,7]", 12));
    assert(assertTwoSum("[1,3]", "[7,8,9]", 16));
    assert(assertTwoSum("[2,3]", "[1,3,6,10]", 9));
    assert(assertTwoSum("[3,4]", "[2,3,-6,10]", 4));
    assert(assertTwoSum("[3,4]", "[2,3,6,-10]", -4));
}

int assertTwoSum(char * expect, char * array, int target)
{
    int * nums = stringToIntArray(array);
    int size = countArrayInString(array);
    int * out = twoSum(nums, size, target);
    int status = 1;
    if (!assertIntArray(expect, out)) status = 0;
    free(nums);
    free(out);
    return status;
}

