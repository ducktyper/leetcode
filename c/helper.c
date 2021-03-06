#include "helper.h"

int helperPrintSuccess()
{
    printf(".");
    return 1;
}

int helperAssertInt(int expect, int actual)
{
    if (expect == actual) return helperPrintSuccess();
    printf("\nExpected: %i\n  Actual: %i\n", expect, actual);
    return 0;
}

int helperAssertLong(long expect, long actual)
{
    if (expect == actual) return helperPrintSuccess();
    printf("\nExpected: %li\n  Actual: %li\n", expect, actual);
    return 0;
}

int helperAssertDouble(double expect, double actual)
{
    if (expect == actual) return helperPrintSuccess();
    printf("\nExpected: %f\n  Actual: %f\n", expect, actual);
    return 0;
}

int helperAssertString(char * expect, char * actual)
{
    if (strcmp(expect, actual) == 0) return helperPrintSuccess();
    printf("\nExpected: %s\n  Actual: %s\n", expect, actual);
    return 0;
}

int countArrayInString(char * array)
{
    if (strcmp(array, "[]") == 0) return 0;
    int size = 1;
    while (*array)
    {
        if (*array == ',') size++;
        array++;
    }
    return size;
}

int countArrayOfArrayInString(char * array)
{
    if (strcmp(array, "[]") == 0) return 0;
    int size = 1;
    int ignore = 0;
    array++;
    while (*array)
    {
        if      (*array == '[') ignore = 1;
        else if (*array == ']') ignore = 0;
        else if (*array == ',' && !ignore) size++;
        array++;
    }
    return size;
}

int * stringToIntArray(char * string, int * returnSize)
{
    *returnSize = 0;
    if (strlen(string) == 2) return NULL;
    *returnSize = countArrayInString(string);
    int * out = (int *)malloc(sizeof(int) * (*returnSize));
    char num[15];
    int i = 0, j = 0;
    if (string[0] != '[' || string[strlen(string) - 1] != ']')
    {
        printf("\"%s\" is not int array string (e.g. \"[1,2]\")", string);
        exit(1);
    }
    string++;
    while (*string)
    {
        if (*string == ',' || *string == ']')
        {
            num[i] = '\0';
            out[j++] = atoi(num);
            i = 0;
        }
        else
        {
            if (i >= 15)
            {
                printf("'%s' contains an integer having more than 15 chars", string);
                exit(1);
            }
            num[i] = *string;
            i++;
        }
        string++;
    }
    return out;
}

char ** stringToStringArray(char * string, int * returnSize)
{
    if (strlen(string) == 2) return NULL;
    *returnSize = countArrayInString(string);
    char ** out = (char **)malloc(sizeof(char **) * (*returnSize));
    char tmp[15];
    int i = 0, j = 0;
    if (string[0] != '[' || string[strlen(string) - 1] != ']')
    {
        printf("\"%s\" is not string array string (e.g. \"[a,b]\")", string);
        exit(1);
    }
    string++;
    while (*string)
    {
        if (*string == ',' || *string == ']')
        {
            tmp[i] = '\0';
            char * str = malloc(sizeof(char) * (i + 1));
            memcpy(str, tmp, sizeof(char) * (i + 1));
            out[j++] = str;
            i = 0;
        }
        else
        {
            if (i >= 15)
            {
                printf("'%s' contains an string having more than 15 chars", string);
                exit(1);
            }
            tmp[i] = *string;
            i++;
        }
        string++;
    }
    return out;
}

char * intArrayToString(int * array, int size)
{
    char nums[size * 15];
    int length = (size ? size : 1) + 2;
    for (int i = 0; i < size; i++)
    {
        char * num = &nums[i * 15];
        sprintf(num, "%d", array[i]);
        length += strlen(num);
    }
    char * out = (char *)malloc(sizeof(char) * length);
    int p = 1;
    for (int i = 0; i < size; i++)
    {
        strcpy(&out[p], &nums[i * 15]);
        p += strlen(&nums[i * 15]);
        out[p] = ',';
        p++;
    }
    out[0] = '[';
    out[length - 2] = ']';
    out[length - 1] = '\0';
    return out;
}

char * intArrayOfArrayToString(int ** array, int arraySize, int arrayInSize)
{
    int size = 3 + arraySize - 1;
    char * numsOfNums[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        numsOfNums[i] = intArrayToString(array[i], arrayInSize);
        size += strlen(numsOfNums[i]);
    }
    char * out = (char *)malloc(sizeof(char) * size);
    int j = 0;
    out[j++] = '[';
    for (int i = 0; i < arraySize; i++)
    {
        strcpy(&out[j], numsOfNums[i]);
        j += strlen(numsOfNums[i]);
        free(numsOfNums[i]);
        if (i + 1 < arraySize) out[j++] = ',';
    }
    out[j++] = ']';
    out[j++] = '\0';
    return out;
}

char * stringArrayToString(char ** array, int size)
{
    int length = (size ? size : 1) + 2;
    for (int i = 0; i < size; i++) length += strlen(array[i]);
    char * out = (char *)malloc(sizeof(char) * length);
    int p = 1;
    for (int i = 0; i < size; i++)
    {
        strcpy(&out[p], array[i]);
        p += strlen(array[i]);
        out[p++] = ',';
    }
    out[0] = '[';
    out[length - 2] = ']';
    out[length - 1] = '\0';
    return out;
}

void freeStringArray(char ** array, int size)
{
    for (int i = 0; i < size; i++) free(array[i]);
    free(array);
}

int helperAssertIntArray(char * expect, int * actual)
{
    int size = countArrayInString(expect);
    char * actualString = intArrayToString(actual, size);
    int status = 0;
    if (strcmp(expect, actualString) == 0)
        status = helperPrintSuccess();
    else
    {
        printf("\nExpected: %s\n  Actual: %s\n", expect, actualString);
    }
    free(actualString);
    return status;
}

struct ListNode * stringToListNode(char * listNodeString)
{
    int arraySize;
    int * array   = stringToIntArray(listNodeString, &arraySize);

    struct ListNode base = {0, NULL};
    struct ListNode * prev = &base;
    for(int i = 0; i < arraySize; i++)
    {
        struct ListNode * node = malloc(sizeof(struct ListNode));
        node -> val  = array[i];
        node -> next = NULL;
        prev -> next = node;
        prev = node;
    }

    free(array);
    return base.next;
}

struct ListNode ** stringToListNodeOfListNode(char * str, int * returnSize)
{
    *returnSize = countArrayOfArrayInString(str);
    struct ListNode ** out = malloc(sizeof(struct ListNode **) * (*returnSize));
    int j = 0;
    if (*returnSize == 0) return out;

    int length = strlen(str), start;
    for(int i = 1; i < length - 1; i++)
    {
        if (str[i] == '[') start = i;
        else if (str[i] == ']')
        {
            // char sub[i - start + 2];
            char * sub = malloc(sizeof(char) * (i - start + 2));
            memcpy(sub, &str[start], sizeof(char) * (i - start + 1));
            sub[i - start + 1] = '\0';
            out[j++] = stringToListNode(sub);
            free(sub);
        }
    }
    return out;
}

char * listNodeToString(struct ListNode * head)
{
    int size = 0;
    struct ListNode * node = head;
    while(node != NULL) { size++; node = node -> next; }

    int intArray[size];
    int * p = intArray;
    node = head;
    while (node != NULL)
    {
        *(p++) = node -> val;
        node   = node -> next;
    }
    return intArrayToString(intArray, size);
}

char * listNodeOfListNodeToString(struct ListNode ** listNodeOfListNode, int size)
{
    char * lists[size];
    int length = 3;
    for(int i = 0; i < size; i++)
    {
        lists[i] = listNodeToString(listNodeOfListNode[i]);
        length += strlen(lists[i]);
    }
    if (size) length += size - 1;
    char * out = malloc(sizeof(char) * length);
    int j = 1;
    for(int i = 0; i < size; i++)
    {
        int l = strlen(lists[i]);
        memcpy(&out[j], lists[i], sizeof(char) * l);
        j += l;
        out[j++] = ',';
        free(lists[i]);
    }
    out[0] = '[';
    out[length - 2] = ']';
    out[length - 1] = '\0';
    return out;
}

void freeListNode(struct ListNode * node)
{
    while (node)
    {
        struct ListNode * current = node;
        node = node -> next;
        free(current);
    }
}

void freeListNodeOfListNode(struct ListNode ** node, int size)
{
    for (int i = 0; i < size; i++) freeListNode(node[i]);
    free(node);
}

int helperPrint(char * file, int line)
{
    printf("Assertion failed at %s:%d\n", file, line);
    return 0;
}
