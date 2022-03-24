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
        node* ptr = head;
        node* prev = NULL;
        while(ptr != last) {
            node* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        node* ptr = head;
        node* ans = NULL;
        node* prev = NULL;
        while(ptr) {
            for(int i=0;i<k;i++) {
                if (!ptr) return ans;
                ptr = ptr->next;
            }
            node* kth = reverse(head, ptr);
            if (!prev) prev = head;
            else {
                prev->next = kth;
                prev = head;
            }
            if (!ans) ans = kth;
            head->next = ptr;
            head = ptr;
        }
        return ans;
    }
};


// k = 3 
// 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7
    
