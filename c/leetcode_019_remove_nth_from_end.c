struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * SOURCE: https://leetcode.com/problems/remove-nth-node-from-end-of-list
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode pre = {0, head};
    struct ListNode * current = &pre, * target = &pre;

    for (int i = 0; i < n; i++) current = current -> next;
    while (current -> next != NULL)
    {
        current = current -> next;
        target  = target -> next;
    }

    target -> next = target -> next -> next;

    return pre.next;
}
