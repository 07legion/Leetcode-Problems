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
    node* func(node* head) {
        if (head->next == NULL) 
            return head;
        node* ans = func(head->next);
        head->next->next = head;
        head->next = NULL;
        return ans;
    }
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        return func(head);
        
        // node* ptr = head;
        // node* prev = NULL;
        // while(ptr) {
        //     node* temp = ptr->next;
        //     ptr->next = prev;
        //     prev = ptr;
        //     ptr = temp;
        // }
        // return prev;
    }
};