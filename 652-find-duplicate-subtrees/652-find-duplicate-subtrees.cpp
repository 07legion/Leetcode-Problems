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
    map<string, int> mp;
    vector<node*> ans;
public:
    string func(node* root) {
        if (!root) return "";
        string left = func(root->left);
        string right = func(root->right);
        string temp = to_string(root->val) + "-" + left + "-" + right;
        if (mp[temp] == 1) ans.push_back(root);
        mp[temp]++;
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        mp.clear(); ans.clear();
        func(root);
        return ans;
    }
};