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
    node* merge(node* head1, node* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        node* ptr1 = head1;
        node* ptr2 = head2;
        if (ptr2->val < ptr1->val) swap(ptr1, ptr2);
        node* prev = NULL;
        node* ans = NULL;
        while(ptr1 || ptr2) {
            if (!ptr1) {
                prev->next = ptr2;
                break;
            }
            if (!ptr2) {
                break;
            }
            if (ptr1->val <= ptr2->val) {
                if (!ans) ans = ptr1;
                prev = ptr1;
                ptr1 = ptr1->next;
            } else {
                prev->next = ptr2;
                prev = ptr2;
                ptr2 = ptr2->next;
                prev->next = ptr1;
            }
        }
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& v) {
        if (!v.size()) return NULL;
        int n = v.size();
        int temp = n;
        while(temp > 1) {
            int i = 0, j = temp-1, l = 0;
            while(i < j) {
                v[l++] = merge(v[i++], v[j--]);
            }
            // temp = (temp % 2 ? 1 + temp / 2 : temp / 2);
            temp = (temp + 1) / 2;
        }
        return v[0];
    }
};