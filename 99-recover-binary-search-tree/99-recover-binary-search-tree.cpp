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
    node* a;
    node* b;
    node* prev;
public:
    void func(node* root) {
        if (!root) return;
        func(root->left);
        if (!a) {
            if (prev && prev->val > root->val) {
                a = prev;
            }
        } 
        if (a && prev && prev->val > root->val) {
            b = root;
        }
        prev = root;
        func(root->right);
    }
    void recoverTree(TreeNode* root) {
        a = NULL; b = NULL;
        prev = NULL;
        func(root);
        swap(a->val, b->val);
    }
};