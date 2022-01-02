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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        node* ans = head->next;
        node* ptr = head;
        node *old = NULL;
        // 2 -> 1 -> 3 -> 4 -> 5 -> 6
        while(ptr && ptr->next) {
            node* first = ptr;
            node* second = first->next;
            node* third = second->next;
            second->next = first;
            first->next = third;
            if (!old) old = ptr;
            else old->next = second, old = ptr;
            ptr = ptr->next;
        }
        return ans;
    }
};