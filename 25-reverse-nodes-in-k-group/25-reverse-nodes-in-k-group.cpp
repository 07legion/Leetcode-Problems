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
    node* reverseLL(node* start, node* end) {
        node* curr = start;
        node* prev = NULL;
        while(curr != end) {
            node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !k) return head;
        node *ptr = head;
        node* prev = NULL;
        node* ans = NULL;
        while(ptr) {
            for(int i=0;i<k;i++) {
                if (!ptr) return ans;
                ptr = ptr->next;
            }
            node* newHead = reverseLL(head, ptr);
            if (!ans) ans = newHead;
            if (!prev) prev = head;
            else {
                prev->next = newHead;
                prev = head;
            }
            head->next = ptr;
            head = ptr;
        }
        return ans;
    }
};

// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7

// 3 -> 2 -> 1 -> 4 -> 5 -> 6
    



// k = 3 
// 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7
   // n         h    p
