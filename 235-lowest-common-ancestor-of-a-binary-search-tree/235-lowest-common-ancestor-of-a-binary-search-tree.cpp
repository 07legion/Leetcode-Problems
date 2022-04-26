/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using node = TreeNode;
class Solution {
public:
    node* func(node* root, node* p, node* q) {
        if (p->val < root->val && q->val < root->val) {
            return func(root->left, p, q);
        } 
        else if (p->val > root->val && q->val > root->val) {
            return func(root->right, p, q);
        } 
        return root;
    }
    // node* func(node* root, node* p, node* q) {
    //     node* curr = root;
    //     while(true) {
    //         if (!curr) return curr;
    //         if (p->val < curr->val && q->val < curr->val) curr = curr->left;
    //         else if (p->val > curr->val && q->val > curr->val) curr = curr->right;
    //         else return curr;
    //     }
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return root;
        return func(root, p, q);
    }
};