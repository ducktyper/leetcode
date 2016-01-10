#include "helper.h"
#include "leetcode_023_merge_k_lists.c"

int assertMergeKLists(char * expected, char * listsString);

int main()
{
    assert(assertMergeKLists("[]", "[[]]"));
    assert(assertMergeKLists("[1,2,3,4]", "[[1,2],[3,4]]"));
    assert(assertMergeKLists("[1,2,3,4]", "[[1,3],[2,4]]"));
    assert(assertMergeKLists("[-1,5,6,10,11]", "[[],[-1,5,11],[],[6,10]]"));
}

int assertMergeKLists(char * expected, char * listsString)
{
    int size;
    struct ListNode ** lists = stringToListNodeOfListNode(listsString, &size);
    struct ListNode * out = mergeKLists(lists, size);
    char * actual = listNodeToString(out);
    int status = 1;
    if (!assertString(expected, actual)) status = 0;

    freeListNodeOfListNode(lists, size);
    freeListNode(out);
    free(actual);

    return status;
}
