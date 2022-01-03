/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
using node = ListNode;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        node* head1 = NULL;
        node* prev = NULL;
        node* ptr1 = head;
        node* ptr2 = NULL;
        node* newHead = NULL;
        while(ptr1) {
            if (ptr1->val < x) {
                if(!newHead) newHead = ptr1;
                if (prev) prev->next = ptr1;
                prev = ptr1;
            } else {
                if (!head1) head1 = ptr1;
                else ptr2->next = ptr1;
                ptr2 = ptr1;
            }
            ptr1 = ptr1->next;
        }
        if (prev)
            prev->next = head1;
        if (ptr2)
            ptr2->next = NULL;
        if (!newHead) return head;
        return newHead;
    }
};