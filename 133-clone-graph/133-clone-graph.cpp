/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

using node = Node;
class Solution {
private:
    map<node* , node* > mp;
public:
    void func(node* root) {
        if (!root) return;
        for(auto it:root->neighbors) {
            if (mp.find(it) != mp.end()) {
                mp[root]->neighbors.push_back(mp[it]);
                continue;
            }
            node* temp = new node(it->val);
            mp[it] = temp;
            mp[root]->neighbors.push_back(temp);
            func(it);
        }
    }
    Node* cloneGraph(Node* root) {
        if (!root) return root;
        mp[root] = new node(root->val);
        func(root);
        return mp[root];
    }
};