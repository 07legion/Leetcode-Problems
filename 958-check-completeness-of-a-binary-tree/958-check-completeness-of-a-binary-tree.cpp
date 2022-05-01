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
    bool isCompleteTree(TreeNode* root) {
        queue<node* > q;
        q.push(root);
        bool flag = false;
        while(!q.empty()) {
            node* temp = q.front();
            q.pop();
            if (!temp) {
                flag = true;
                continue;
            }
            if (temp && flag) return false;
            q.push(temp->left);
            q.push(temp->right);
        } 
        return true;
    }
};