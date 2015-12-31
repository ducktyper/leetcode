#include "helper.h"
#include "leetcode_016_3sum_closest.c"

int assertThreeSumClosest(int expected, char * nums, int target);

int main()
{
    assert(assertThreeSumClosest(6, "[1,2,3]", 7));
    assert(assertThreeSumClosest(1110, "[1,10,100,1000,10000,100000]", 1111));
    assert(assertThreeSumClosest(82, "[1,2,4,8,16,32,64,128]", 82));
}

int assertThreeSumClosest(int expected, char * numsString, int target)
{
    int * nums = stringToIntArray(numsString);
    int numsSize = countArrayInString(numsString);
    int status = 1;
    if (!assertInt(expected, threeSumClosest(nums, numsSize, target))) status = 0;
    return status;
}
