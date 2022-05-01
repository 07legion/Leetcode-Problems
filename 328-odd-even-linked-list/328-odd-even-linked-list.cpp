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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        node* odd = NULL;
        node* even = NULL;
        node* curr = head;
        node* oddHead = NULL;
        node* evenHead = NULL;
        int i = 1;
        while(curr) {
            if (i % 2) {
                if (!odd) odd = curr, oddHead = curr;
                else {
                    odd->next = curr;
                    odd = curr;
                }
            } else {
                if (!even) even = curr, evenHead = curr;
                else {
                    even->next = curr;
                    even = curr;
                }
            }
            i++;
            curr = curr->next;
        }
        if (even) even->next = NULL;
        if (odd) odd->next = evenHead;
        return oddHead == NULL ? evenHead : oddHead;
    }
};

// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7

// 1 -> 3 -> 5 -> 7 -> 2 -> 4 -> 6