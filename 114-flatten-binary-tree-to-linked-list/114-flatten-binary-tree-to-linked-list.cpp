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
    node* prev;
public:
    void func(node* root) {
        if (!root) return;
        func(root->right);
        func(root->left);
        if (!prev) {
            prev = root;
        } else {
            root->right = prev;
            root->left = NULL;
            prev = root;
        }
    }
    void flatten(TreeNode* root) {
        prev = NULL;
        func(root);
    }
};