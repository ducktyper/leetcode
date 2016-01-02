#include "helper.h"
#include "leetcode_019_remove_nth_from_end.c"

int assertRemoveNthFromEnd(char * expected, char * arrayString, int n);
void freeListNode(struct ListNode * node);

int main()
{
    assert(assertRemoveNthFromEnd("[]", "[1]", 1));
    assert(assertRemoveNthFromEnd("[1,2,3,5]", "[1,2,3,4,5]", 2));
}

int assertRemoveNthFromEnd(char * expected, char * arrayString, int n)
{
    int * array   = stringToIntArray(arrayString);
    int arraySize = countArrayInString(arrayString);

    struct ListNode nodes[arraySize];
    for(int i = 0; i < arraySize; i++)
    {
        nodes[i].val  = array[i];
        nodes[i].next = (i + 1 == arraySize ? NULL : &nodes[i + 1]);
    }

    struct ListNode * out = removeNthFromEnd(&nodes[0], n);

    int outArray[arraySize];
    int * p = outArray;
    while (out != NULL)
    {
        *(p++) = out -> val;
        out    = out -> next;
    }
    char * actual = intArrayToString(outArray, arraySize - 1);

    int status = 1;
    if (!assertString(expected, actual)) status = 0;

    free(array);
    free(actual);

    return status;
}
