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
    node* reverse(node* head, node* last) {
        node* prev = head;
        node* curr = head;
        while(curr != last) {
            node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        node* curr = head;
        for(int i=0;i<k;i++) {
            if (!curr) return head;
            curr = curr->next;
        }
        node* ans = reverse(head, curr);
        head->next = reverseKGroup(curr, k);
        return ans;
    }
};