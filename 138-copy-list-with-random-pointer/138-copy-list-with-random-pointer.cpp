/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

using node = Node;
class Solution {
private:
    map<node* , node* > mp;
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        node* ptr = head;
        node* ans = NULL;

        while(ptr) {
            node* p = ptr->next;
            node* temp = new node(ptr->val);
            temp->next = p;
            ptr->next = temp;
            ptr = p;
        }
        ptr = head;
        while(ptr && ptr->next) {
            node* p = ptr->next; 
            if (ptr->random)
                p->random = ptr->random->next;
            else p->random = NULL;
            ptr = p->next;
        }
        ptr = head;
        node* prev = NULL;
        while(ptr && ptr->next) {
            node* p = ptr->next;
            if (!ans) {
                ans = p;
                prev = p;
            } else {
                prev->next = p;
                prev = p;
            }
            if (p) ptr->next = p->next;
            else ptr->next = NULL;
            ptr = p->next;
        }
        ptr = ans;
        return ans;
    }
};