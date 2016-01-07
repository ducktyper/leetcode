#include "helper.h"
#include "leetcode_021_merge_two_lists.c"

int assertMergeTwoLists(char * expected, char * l1String, char * l2String);

int main()
{
    assert(assertMergeTwoLists("[1,2,3,4]", "[1,2]", "[3,4]"));
    assert(assertMergeTwoLists("[3,4]", "[]", "[3,4]"));
    assert(assertMergeTwoLists("[1,3,4]", "[1]", "[3,4]"));
    assert(assertMergeTwoLists("[1,2,4]", "[2]", "[1,4]"));
}

int assertMergeTwoLists(char * expected, char * l1String, char * l2String)
{
    struct ListNode * l1 = stringToListNode(l1String);
    struct ListNode * l2 = stringToListNode(l2String);
    struct ListNode * out = mergeTwoLists(l1, l2);
    char * actual = listNodeToString(out);
    int status = 1;
    if (!assertString(expected, actual)) status = 0;

    freeListNode(l1);
    freeListNode(l2);
    freeListNode(out);
    free(actual);

    return status;
}
