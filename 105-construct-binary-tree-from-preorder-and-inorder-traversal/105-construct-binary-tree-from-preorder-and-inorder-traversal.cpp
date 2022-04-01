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
    unordered_map<int, int> mp;
    vector<int> pre, in;
    int n, a;
public:
    node* func(int start, int end) {
        if (start > end) return NULL;
        node* root = new node();
        int val = pre[a++];
        root->val = val;
        root->left = func(start, mp[val]-1);
        root->right = func(mp[val]+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre1, vector<int>& in1) {
        in = in1; pre = pre1;
        n = in.size();
        a = 0;
        for(int i=0;i<n;i++) mp[in[i]] = i;
        return func(0, n-1);
    }
};