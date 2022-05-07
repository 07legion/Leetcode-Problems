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
class Solution {
private:
    int sm;
public:
    bool func(TreeNode* root, int target) {
        if (!root) return false;
        if (root->left == NULL && root->right == NULL) {
            if (target - (root->val) == 0) return true;
            return false;
        }
        return func(root->left, target - root->val) || func(root->right, target - root->val);
    }
    bool hasPathSum(TreeNode* root, int target) {
        sm = 0;
        if (!root) return false;
        return func(root, target);
    }
};

// [5,4,8,11,null,13,4,7,2,null,null,null,1]
// 22
// [1,2,3]
// 5
// [1,2]
// 0
// []
// 0
// [1,2]
// 1