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
    ll sm;
    ll mxSum;
};
class Solution {
public:
    info func(node* root) {
        if (!root) return {LLONG_MAX, LLONG_MIN, true, 0ll, 0ll};
        info l = func(root->left);
        info r = func(root->right);
        info res;
        res.sm = l.sm + r.sm + root->val;
        if (root->val > l.mx && root->val < r.mn && l.isBst && r.isBst) {
            res.mxSum = max({l.mxSum, r.mxSum, res.sm});
            res.isBst = true;
            res.mn = min({ll(root->val), l.mn, r.mn});
            res.mx = max({ll(root->val), l.mx, r.mx});
            return res;
        }
        res.isBst = false;
        res.mxSum = max(l.mxSum, r.mxSum);
        return res;
    }
    int maxSumBST(TreeNode* root) {
        return func(root).mxSum;
    }
};