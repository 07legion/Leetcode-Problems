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
        if (!root) return root;
        if (root->val == p->val || root->val == q->val) return root;
        node* a = func(root->left, p, q);
        node* b = func(root->right, p, q);
        if (a && b) return root;
        else if (!a && b) return b;
        else return a;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // ans = NULL;
        // return ans;
        return func(root, p, q);
    }
};