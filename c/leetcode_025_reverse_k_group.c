/**
 * SOURCE: https://leetcode.com/problems/reverse-nodes-in-k-group
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * reverseKNodes(struct ListNode * head, int k);

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head) return head;
    struct ListNode pre = {0, head}, * n = &pre;
    while(n) n = reverseKNodes(n, k);
    return pre.next;
}

struct ListNode * reverseKNodes(struct ListNode * pre, int k)
{
    if (k <= 1 || !(pre -> next)) return pre -> next;

    struct ListNode * half, * first = pre -> next, * last = pre;

    for (int i = 1; i <= k; i++)
    {
        last = last -> next;
        if (!last)      return NULL;
        if (i == k / 2) half = last;
    }

    pre  -> next = half -> next;
    half -> next = last -> next;
    last -> next = first;

    return reverseKNodes(reverseKNodes(pre, k / 2 + k % 2), k / 2);
}
