/**
 * SOURCE: https://leetcode.com/problems/swap-nodes-in-pairs
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode pre = {0, head};
    struct ListNode * from = &pre;
    while(head && head -> next)
    {
        from -> next = head -> next;
        head -> next = head -> next -> next;
        from -> next -> next = head;
        from = head;
        head = from -> next;
    }
    return pre.next;
}
