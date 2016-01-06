/**
 * SOURCE: https://leetcode.com/problems/add-two-numbers
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode empty = {0, NULL}, start = {0, NULL};

    int extra = 0;
    struct ListNode * prev = &start;
    while (l1 || l2 || extra)
    {
        if (!l1) l1 = &empty;
        if (!l2) l2 = &empty;
        int sum = l1 -> val + l2 -> val + extra;
        extra = sum >= 10 ? 1 : 0;
        struct ListNode * node = malloc(sizeof(struct ListNode));
        node -> val  = sum % 10;
        node -> next = NULL;
        prev -> next = node;
        prev = node;
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    return start.next;
}
