/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using node = TreeNode;
class Solution {
private: 
    // vector<int> v3;
    vector<int> v1, v2;    
public:
    void func(node* root1, node* root2) {
        if (!root1 && !root2) return;
        func(root1 ? root1->left : root1, root2 ? root2->left : root2);
        if (root1) v1.push_back(root1->val);
        if (root2) v2.push_back(root2->val);
        func(root1 ? root1->right : root1, root2 ? root2->right : root2);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // vector<int> v1; v3.clear();
        func(root1, root2);
        // vector<int> v2; v3.clear();
        // func(root2);
        vector<int> v(v1.size() + v2.size(), 0);
        int i = 0, j = 0, k = 0;
        while(i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) v[k++] = v1[i++];
            else v[k++] = v2[j++];
        }
        while(i < v1.size()) {
            v[k++] = v1[i++];
        }
        while(j < v2.size()) {
            v[k++] = v2[j++];
        }
        return v;
    }
};