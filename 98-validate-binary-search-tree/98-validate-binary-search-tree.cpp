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
    // bool func(node* root, ll mn, ll mx) {
    //     if (!root) return true;
    //     return root->val > mn && root->val < mx && func(root->left, mn, root->val) && 
    //         func(root->right, root->val, mx);
    // }
    bool func(node* root, node* &prev) {
        if (!root) return true;
        bool a = func(root->left, prev);
        if (prev && root->val <= prev->val) return false;
        prev = root;
        bool b = func(root->right, prev);
        return a && b;
    }
    // bool validate(TreeNode* node, TreeNode* &prev) {
    //     if (node == NULL) return true;
    //     if (!validate(node->left, prev)) return false;
    //     if (prev != NULL && prev->val >= node->val) return false;
    //     prev = node;
    //     return validate(node->right, prev);
    // }
    bool isValidBST(TreeNode* root) { 
        node* prev = NULL;
        return func(root, prev);
        // return func(root, LLONG_MIN, LLONG_MAX);
    }
};