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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        queue<pair<node*, long long int> > q;
        q.push({root, 0});
        long long int ans = -1e9;
        while(!q.empty()) {
            ans = max(ans, q.back().second - q.front().second + 1);
            int len = q.size();
            for(int i=0;i<len;i++) {
                node* n = q.front().first;
                unsigned long long int a = q.front().second;
                q.pop();
                if (n->left) {
                    q.push({n->left, 2 * a * 1ll + 1ll});
                }
                if (n->right) {
                    q.push({n->right, 2 * a * 1ll + 2 * 1ll});
                }
            }
        }
        return ans;
    }
};