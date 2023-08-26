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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* ptr = head;
        ListNode* prev = NULL;
        while(ptr) {
            ListNode* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        if (!head) return head;
        head = reverseList(head);
        int mx = -1e5;
        node* prev = head;
        node* ptr = head->next;
        while(ptr) {
            if (ptr->val < prev->val) {
                prev->next = ptr->next;
                ptr = prev->next;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return reverseList(head);
    }
};


// [5,2,13,3,8]


// 8, 3, 13, 2, 5
