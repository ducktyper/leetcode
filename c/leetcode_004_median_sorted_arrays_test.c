#include "helper.h"
#include "leetcode_004_median_sorted_arrays.c"

int assertMedianSortedArrays(double median, char * array1, char * array2);

int main()
{
    assert(assertMedianSortedArrays(0, "[]", "[]"));
    assert(assertMedianSortedArrays(1, "[1]", "[]"));
    assert(assertMedianSortedArrays(1, "[1]", "[1]"));
    assert(assertMedianSortedArrays(1.5, "[1]", "[2]"));
    assert(assertMedianSortedArrays(2, "[2]", "[1,3]"));
    assert(assertMedianSortedArrays(2, "[1,2]", "[2,3]"));
    assert(assertMedianSortedArrays(2, "[2,3]", "[1,2]"));
    assert(assertMedianSortedArrays(2.5, "[1,2]", "[3,4]"));
    assert(assertMedianSortedArrays(7, "[1,11]", "[6,8]"));
    assert(assertMedianSortedArrays(2, "[1,2,3]", "[1,2,3]"));
    assert(assertMedianSortedArrays(3.5, "[1,2,3]", "[4,5,6]"));
    assert(assertMedianSortedArrays(3.5, "[4,5,6]", "[1,2,3]"));
    assert(assertMedianSortedArrays(3, "[1,2,3]", "[3,4,5]"));
    assert(assertMedianSortedArrays(2.5, "[1,2,3]", "[2,3,4]"));
    assert(assertMedianSortedArrays(2.5, "[1,2,3]", "[1,5,6]"));
    assert(assertMedianSortedArrays(2, "[1,2,3]", "[1,1,3,4]"));
    assert(assertMedianSortedArrays(4.5, "[1,2,3,4]", "[5,6,7,8]"));
    assert(assertMedianSortedArrays(2.5, "[1,2,3,4]", "[1,2,3,4]"));
    assert(assertMedianSortedArrays(3, "[1,2,3,4,5]", "[1,2,3,4,5]"));
    assert(assertMedianSortedArrays(3.5, "[1,2,3,4,5]", "[3,3,4,5,6]"));
    assert(assertMedianSortedArrays(2.5, "[1,2,3,4,5]", "[1,2,3]"));
    assert(assertMedianSortedArrays(4, "[1,2,3,4,5]", "[7,8]"));
    assert(assertMedianSortedArrays(4, "[7,8]", "[1,2,3,4,5]"));
    assert(assertMedianSortedArrays(8, "[7,8,9,11,12]", "[1,2]"));
    assert(assertMedianSortedArrays(8.5, "[7,8,9,11,12]", "[1]"));
    assert(assertMedianSortedArrays(10, "[7,8,9,11,12]", "[15]"));
    assert(assertMedianSortedArrays(9.5, "[7,8,9,11,12]", "[10]"));
    assert(assertMedianSortedArrays(9, "[7,8,9,11,12]", "[6,10]"));
    assert(assertMedianSortedArrays(8.5, "[7,8,10,11]", "[6,9]"));
}

int assertMedianSortedArrays(double median, char * array1, char * array2)
{
    int size1, size2;
    int * nums1 = stringToIntArray(array1, &size1);
    int * nums2 = stringToIntArray(array2, &size2);
    int status = 1;
    if (!assertDouble(median, findMedianSortedArrays(nums1, size1, nums2, size2)))
        status = 0;
    free(nums1);
    free(nums2);
    return status;
}
