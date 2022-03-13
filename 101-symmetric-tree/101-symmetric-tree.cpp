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
public:
    bool func(node* root1, node* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        return root1->val == root2->val && func(root1->right, root2->left) && func(root1->left, root2->right);
    }
    bool isSymmetric(TreeNode* root) {
        return func(root, root);
    }
};