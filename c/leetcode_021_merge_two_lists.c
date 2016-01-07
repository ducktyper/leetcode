/**
 * SOURCE: https://leetcode.com/problems/merge-two-sorted-lists
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode pre = { 0, NULL };
    struct ListNode * last = &pre;
    while(l1 || l2)
    {
        struct ListNode ** sm = (!l2 || (l1 && l1 -> val < l2 -> val)) ? &l1 : &l2;
        struct ListNode * n = malloc(sizeof(struct ListNode));
        n -> val  = (*sm) -> val;
        n -> next = NULL;
        last -> next = n;
        last = last  -> next;
        *sm  = (*sm) -> next;
    }
    return pre.next;
}
