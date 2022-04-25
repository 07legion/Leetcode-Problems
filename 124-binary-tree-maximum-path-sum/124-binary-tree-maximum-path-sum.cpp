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
    int mx;
public:
    int func(node* root) {
        if (!root) return 0;
        int a = func(root->left);
        int b = func(root->right);
        mx = max({mx, root->val, root->val + a, root->val + b, a + root->val + b});
        return max({root->val + a, root->val + b, root->val});
    }
    int maxPathSum(TreeNode* root) {
        mx = INT_MIN;
        func(root);
        return mx;
    }
};