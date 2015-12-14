#include "helper.h"
#include "leetcode_002_add_two_numbers.c"

struct ListNode * numToListNode(long number);
long listNodeToNum(struct ListNode * node);
void freeListNode(struct ListNode * node);
int assertAddTwoNumbers(long sum, long  a, long b);

int main()
{
    assert(assertAddTwoNumbers(25, 12, 13));
    assert(assertAddTwoNumbers(0, 0, 0));
    assert(assertAddTwoNumbers(102, 1, 101));
    assert(assertAddTwoNumbers(9999999999, 9999999999, 0));
}

struct ListNode * numToListNode(long number)
{
    struct ListNode start = {0, NULL};
    struct ListNode * prev = &start;
    do {
        struct ListNode * node = malloc(sizeof(struct ListNode));
        node -> val = number % 10;
        node -> next = NULL;
        prev -> next = node;
        prev = node;
        number /= 10;
    } while (number != 0);
    return start.next;
}

long listNodeToNum(struct ListNode * node)
{
    char nums[15] = {0};
    char num[2];
    int i = 14;
    while (node)
    {
        if (i <= 1)
        {
            printf("ListNode linked to more than 14 nodes");
            exit(1);
        }
        sprintf(num, "%i", node -> val);
        nums[--i] = num[0];
        node = node -> next;
    }
    nums[14] = '\0';
    return atoll(&nums[i]);
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

int assertAddTwoNumbers(long sum, long  a, long b)
{
    struct ListNode * list_node_a = numToListNode(a);
    struct ListNode * list_node_b = numToListNode(b);
    struct ListNode * list_node_sum = addTwoNumbers(list_node_a, list_node_b);
    long num = listNodeToNum(list_node_sum);
    if (!assertLong(sum, num)) return 0;
    freeListNode(list_node_a);
    freeListNode(list_node_b);
    freeListNode(list_node_sum);
    return 1;
}

