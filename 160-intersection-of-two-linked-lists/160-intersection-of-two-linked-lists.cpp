/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using node = ListNode;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        node* p1 = head1;
        node* p2 = head2;
        while(p1 != p2) {
            if (p1 == NULL && p2 == NULL) return NULL;
            if (!p1) p1 = head2;
            else p1 = p1->next;
            if (!p2) p2 = head1;
            else p2 = p2->next;
        }
        return p1 == p2 ? p1 : NULL;
    }
};