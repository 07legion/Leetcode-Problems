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
private:
    node* ans;
public:
//     bool func(node* root, node* p, node* q) {
//         if (!root || !p || !q) return false;
        
//         if (root->val == p->val || root->val == q->val) return true;
        
//         bool a = func(root->left, p, q);
//         bool b = func(root->right, p, q);
        
//         if (a && b) {
//             ans = root; 
//             return true;
//         }
//         if ((root->val == p->val || root->val == q->val) && (a || b)) {
//             ans = root;
//             return true;
//         }
//         if (a || b || root->val == p->val || root->val == q->val) 
//             return true;
//         return false;
//     }
    node* func(node* root, node* p, node* q) {
        if (!root || p == root || q == root) return root;
        node* left = func(root->left, p, q);
        node* right = func(root->right, p, q);
        if (left == NULL) return right;
        else if (right == NULL) return left;
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        return func(root, p, q);
        return ans;
    }
};