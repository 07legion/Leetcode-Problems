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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        if (head2->val < head1->val) swap(head1, head2);
        node* prev = NULL;
        node* ptr1 = head1;
        node* ptr2 = head2;
        while(ptr1 && ptr2) {
            if (ptr1->val <= ptr2->val) {
                if (!prev) prev = ptr1;
                else {
                    prev->next = ptr1; 
                    prev = ptr1;
                }
                ptr1 = ptr1->next;
            } else {
                if (!prev) prev = ptr2;
                else {
                    prev->next = ptr2;
                    prev = ptr2;
                }
                ptr2 = ptr2->next;
            }
        }
        while(ptr1) {
            prev->next = ptr1;
            prev = ptr1;
            ptr1 = ptr1->next;
        }
        while(ptr2) {
            prev->next = ptr2;
            prev = ptr2;
            ptr2 = ptr2->next;
        }
        return head1;
    }    
    ListNode* mergeKLists(vector<ListNode*>& v) {
        if (!v.size()) return NULL;
        int n = v.size();
        while(n > 1) {
            int i = 0, j = n-1;
            while(i < j) {
                v[i] = merge(v[i], v[j]);
                i++; j--;
            }
            n = (n + 1) / 2;
        }
        return v[0];
    }
};