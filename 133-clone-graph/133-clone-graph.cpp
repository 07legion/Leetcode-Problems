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
    map<node* , node*> mp;
public:
    void func(node* u) {
        // mp[u] = new node(u->val);
        for(auto it : u->neighbors) {
            if (mp.find(it) != mp.end()) {
                mp[u]->neighbors.push_back(mp[it]);
                continue;
            }
            node* temp = new node(it->val);
            mp[it] = temp;
            mp[u]->neighbors.push_back(temp);
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



// 1: 2, 4
// 2: 1, 3
// 3: 2, 4
// 4: 1, 3
    
// 1 --- 2      
// |     |
// |     |
// 4 --- 3