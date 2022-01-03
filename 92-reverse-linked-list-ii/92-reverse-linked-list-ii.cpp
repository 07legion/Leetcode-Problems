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
    node* reverseNode(node* head, int i, int right) {
        if (!head || !head->next) return head;
        node* prev = NULL;
        node* last = head;
        node* ptr = head;
        while(ptr && i-1 != right) {
            node* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
            i++;
        }
        if (last) last->next = ptr;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left >= right) return head;
        node* ptr = head;
        node* prev = NULL;
        int i = 1;
        while(ptr) {
            if (i == left) {
                if (!prev)
                    head = reverseNode(ptr, i, right);
                else prev->next = reverseNode(ptr, i, right);
                break;
            }
            prev = ptr;
            i++;
            ptr = ptr->next;
        }
        return head;
    }
};