/**
 * SOURCE: https://leetcode.com/problems/merge-k-sorted-lists
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int minIndex(struct ListNode** lists, int listsSize, int * nextMin);
void swap(struct ListNode** lists, int i, int j);
void quickSort(struct ListNode** lists, int from, int to);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode ** l = malloc(sizeof(struct ListNode **) * listsSize);
    memcpy(l, lists, sizeof(struct ListNode **) * listsSize);
    quickSort(l, 0, listsSize - 1);

    struct ListNode base = { 0, NULL };
    struct ListNode * node = &base;

    int i = 0;
    while (i < listsSize)
    {
        if (!l[i]) { i++; continue; }
        node -> next = malloc(sizeof(struct ListNode));
        node = node -> next;
        node -> val = l[i] -> val;
        node -> next = NULL;
        l[i] = l[i] -> next;
        if (l[i])
        {
            int j = i;
            while(j < listsSize - 1 && l[j] -> val > l[j + 1] -> val)
            {
                swap(l, j, j + 1);
                j++;
            }
        }
    }

    free(l);
    return base.next;
}

void swap(struct ListNode** lists, int i, int j)
{
    struct ListNode * c = lists[i]; lists[i] = lists[j]; lists[j] = c;
}

void quickSort(struct ListNode** lists, int from, int to)
{
    if (from > to) return;
    int pivot = lists[to] ? lists[to] -> val : INT_MIN, p = from;
    for (int i = from; i < to; i++)
    {
        if (!lists[i] || lists[i] -> val <= pivot) swap(lists, i, p++);
    }
    swap(lists, p, to);
    quickSort(lists, from, p - 1);
    quickSort(lists, p + 1, to);
}
