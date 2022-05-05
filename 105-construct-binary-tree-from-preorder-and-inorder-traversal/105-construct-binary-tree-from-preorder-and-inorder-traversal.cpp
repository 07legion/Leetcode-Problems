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
    vector<int> pre, in;
    map<int, int> mp;
public:
    node* func(int& i, int start, int end) {
        if (i == pre.size() || start > end) return NULL;
        int rootVal = pre[i++];
        node* root = new node(rootVal);
        root->left = func(i, start, mp[rootVal]-1);
        root->right = func(i, mp[rootVal]+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre1, vector<int>& in1) {
        pre = pre1; in = in1;
        for(int i=0;i<in.size();i++) mp[in[i]] = i;
        int i = 0;
        return func(i, 0, in.size()-1);
    }
};