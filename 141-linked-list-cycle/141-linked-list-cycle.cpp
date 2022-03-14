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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        node* slow = head;
        node* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;            
        }
        return slow == fast;
    }
};