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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        node* ptr1 = head1;
        node* ptr2 = head2;
        node* prev = NULL;
        node* ans = head1;
        int carry = 0;
        while(ptr1 && ptr2) {
            int temp = ptr1->val + ptr2->val + carry;
            ptr1->val = temp % 10;
            carry = temp / 10;
            prev = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (!ptr1) {
            if (prev)
               prev->next = ptr2;
        }
        // prev = prev->next;
        ptr1 = prev->next;
        while(ptr1) {
            int temp = carry + ptr1->val;
            ptr1->val = temp % 10;
            carry = temp / 10;
            prev = ptr1;
            ptr1 = ptr1->next;
        }
        if (carry > 0) {
            prev->next = new node(carry, NULL);
        }
        return ans;
    }
};