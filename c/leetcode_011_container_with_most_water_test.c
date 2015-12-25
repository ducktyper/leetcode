#include "helper.h"
#include "leetcode_011_container_with_most_water.c"

int assertMaxArea(int max, char * array);

int main()
{
    assert(assertMaxArea(6, "[1,2,3,4,5]"));
}

int assertMaxArea(int max, char * array)
{
    int * heights = stringToIntArray(array);
    int heightSize = countArrayInString(array);
    int status = 1;
    if (!assertInt(max, maxArea(heights, heightSize))) status = 0;
    free(heights);
    return status;
}
