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
    void func(node* root, node* parent, int val) {
        if (!root) {
            node* temp = new node(val, NULL, NULL);
            if (parent && val < parent->val) parent->left = temp;
            if (parent && val > parent->val) parent->right = temp;
            return;
        }
        if (!parent && !root && val < parent->val && val > root->val) {
            node* temp = new node(val, NULL, NULL);
            parent->left = temp;
            temp->left = root;
            return;
        } else if (!parent && !root && val > parent->val && val < root->val) {
            node* temp = new node(val, NULL, NULL);
            parent->right = temp;
            temp->right = root;
            return;
        }
        if (val < root->val) {
            func(root->left, root, val);
        } else func(root->right, root, val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            node* temp = new node(val, NULL, NULL);
            return temp;
        }
        func(root, NULL, val);
        return root;
    }
};