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

typedef long long int ll;
using node = TreeNode;
class Solution {
public:
    bool func(node* root, ll mn, ll mx) {
        if (!root) return true;
        return root->val > mn && root->val < mx && func(root->left, mn, root->val) && 
            func(root->right, root->val, mx);
    }
    bool isValidBST(TreeNode* root) { 
        return func(root, LLONG_MIN, LLONG_MAX);
    }
};