#include "helper.h"

int main()
{
    assertInt(1, 1);
    printf("\nExpected fail at line 7");
    assertInt(1, 2);

    assertDouble(2.0, 2.0);
    printf("\nExpected fail at line 11");
    assertDouble(2.0, 2.1);

    assertLong(2, 2);
    printf("\nExpected fail at line 15");
    assertLong(2, 3);

    assertString("aa", "aa");
    printf("\nExpected fail at line 19");
    assertString("aa", "bb");

    assertInt(0, countArrayInString("[]"));
    assertInt(1, countArrayInString("[1]"));
    assertInt(2, countArrayInString("[1,2]"));

    int array1Size;
    int * array1 = stringToIntArray("[1,2,-3]", &array1Size);
    char * array1String = intArrayToString(array1, array1Size);
    assertIntArray(array1String, array1);
    printf("\nExpected fail at line 29");
    assertIntArray("[1,2,-3,5]", array1);
    int stringArray1Size;
    char ** stringArray1 = stringToStringArray("[a,b]", &stringArray1Size);
    char * stringArray1string = stringArrayToString(stringArray1, stringArray1Size);
    assertString("[a,b]", stringArray1string);
    free(array1);
    free(array1String);
    freeStringArray(stringArray1, 2);

    int array2Sub1[3] = {1,2,-3};
    int array2Sub2[3] = {10,20,30};
    int ** array2[2] = {(int **)&array2Sub1, (int **)&array2Sub2};
    char * array2String = intArrayOfArrayToString((int **) array2, 2, 3);
    assertString("[[1,2,-3],[10,20,30]]", array2String);
    assertInt(2, countArrayOfArrayInString(array2String));
    printf("\nExpected fail at line 44");
    assertString("[[1,2,3],[10,20,30]]", array2String);
    free(array2String);

    struct ListNode * node3 = stringToListNode("[1,2,3]");
    char * node3String = listNodeToString(node3);
    assertString("[1,2,3]", node3String);
    freeListNode(node3);

    int listNodeOfListNode4Size;
    struct ListNode ** nodeList4 = stringToListNodeOfListNode("[[1,2],[3,4]]", &listNodeOfListNode4Size);
    char * nodeList4String = listNodeOfListNodeToString(nodeList4, 2);
    assertString("[[1,2],[3,4]]", nodeList4String);
    freeListNodeOfListNode(nodeList4, listNodeOfListNode4Size);
    free(nodeList4String);
}

