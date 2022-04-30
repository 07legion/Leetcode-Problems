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
struct info {
    ll mn;
    ll mx;
    bool isBst;
};
class Solution {
public:
    // bool func(node* root, ll mn, ll mx) {
    //     if (!root) return true;
    //     return root->val > mn && root->val < mx && func(root->left, mn, root->val) && 
    //         func(root->right, root->val, mx);
    // }
    
    // bool func(node* root, node* &prev) {
    //     if (!root) return true;
    //     bool a = func(root->left, prev);
    //     if (prev && root->val <= prev->val) return false;
    //     prev = root;
    //     bool b = func(root->right, prev);
    //     return a && b;
    // }
    
    info func(node* root) {
        if (!root) return {LLONG_MAX, LLONG_MIN, true};
        info a = func(root->left);
        info b = func(root->right);
        info ans;
        ans.isBst = a.isBst && b.isBst && root->val > a.mx && root->val < b.mn;
        ans.mn = min({a.mn, b.mn, ll(root->val)});
        ans.mx = max({a.mx, b.mx, ll(root->val)});
        return ans;
    }
    
    bool isValidBST(TreeNode* root) { 
        info a = func(root); return a.isBst;
        // node* prev = NULL;
        // return func(root, prev);
        
        // return func(root, LLONG_MIN, LLONG_MAX);
    }
};