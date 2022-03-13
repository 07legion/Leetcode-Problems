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
        node* curr = head;
        node* prev = head;
        while(curr != last) {
            node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        node* ptr = head;
        for(int i=0;i<k;i++) {
            if (!ptr) return head;
            ptr = ptr->next;
        }
        node* ans = reverse(head, ptr);
        head->next = reverseKGroup(ptr, k);
        return ans;
    }
};