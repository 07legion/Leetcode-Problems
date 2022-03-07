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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if (!h1) return h2;
        if (!h2) return h1;
        if (h1->val > h2->val) swap(h1, h2);
        node* head = h1;
        node* prev = h1;
        while(h1 || h2) {
            if (h1 && !h2) {
                break;
            }
            if (!h1 && h2) {
                prev->next = h2;
                break;
            }
            if (h1->val <= h2->val) {
                prev = h1;
                h1 = h1->next;
            } else {
                prev->next = h2;
                prev = h2;
                node* temp = h2->next;
                prev->next = h1;
                h2 = temp;
            }
        }
        return head;
    }
};