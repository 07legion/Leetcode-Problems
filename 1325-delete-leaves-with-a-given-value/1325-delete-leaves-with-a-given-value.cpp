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
    int target;
    bool flag;
public:
    void func(node* root, node* parent, char ch) {
        if (!root) return;
        func(root->left, root, 'l');
        func(root->right, root, 'r');
        if (root && !root->left && !root->right && root->val == target) {
            if (!parent) {
                root = NULL;
                flag = true;
            }
            else {
                if (ch == 'l') parent->left = NULL;
                else if (ch == 'r') parent->right = NULL;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        if (!root) return root;
        target = t;
        flag = false;
        func(root, NULL, ' ');
        if (flag) return NULL;
        return root;
    }
};