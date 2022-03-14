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
        map<node*, node* > mp;
        node* ptr = head;
        node* ans = NULL;
        while(ptr) {
            node* temp = new node(ptr->val);
            if (!ans) ans = temp;
            mp[ptr] = temp;
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr) {
            if (mp.find(ptr->next) != mp.end())
                mp[ptr]->next = mp[ptr->next];
            else mp[ptr]->next = NULL;
            if (mp.find(ptr->random) != mp.end())
                mp[ptr]->random = mp[ptr->random];
            else mp[ptr]->random = NULL;
            ptr = ptr->next;
        }
        return ans;
    }
};