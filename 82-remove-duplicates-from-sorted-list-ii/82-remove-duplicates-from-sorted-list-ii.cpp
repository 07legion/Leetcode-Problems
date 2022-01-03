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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        node* ptr = head;
        int i = 0;
        node* prev = NULL;
        while(ptr) {
            if (ptr->next && ptr->val == ptr->next->val) {
                int t = ptr->val;
                while(ptr && ptr->val == t) {
                    ptr = ptr->next;
                }
                if (!ptr && prev) {
                    prev->next = NULL;
                }
            } else {
                if (!i) head = ptr, prev = ptr;
                else prev->next = ptr, prev = ptr;
                // cout<<ptr->val<<" ";
                ptr = ptr->next;
                i++;
            }
        }
        if (!prev) return prev;
        return head;
    }
};