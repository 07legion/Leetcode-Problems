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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) return head;
        if (k == 0) return head;
        int i = 1;
        node* ptr = head;
        for(i=1;i<k;i++) {
            ptr = ptr->next;
        }
        node* slow = head;
        node* fast = ptr;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        int temp = slow->val;
        slow->val = ptr->val;
        ptr->val = temp;
        return head;
    }
};