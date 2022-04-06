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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (!root) return ans;
        stack<node* > st1, st2;
        st1.push(root);
        int i = 0;
        while(!st1.empty() || !st2.empty()) {
            vector<int> temp;
            if (i % 2 == 0) {
                // left to right
                while(!st1.empty()) {
                    temp.push_back(st1.top()->val);
                    if (st1.top()->left) st2.push(st1.top()->left);
                    if (st1.top()->right) st2.push(st1.top()->right);
                    st1.pop();
                }
            } else {
                // right to left
                while(!st2.empty()) {
                    temp.push_back(st2.top()->val);
                    if (st2.top()->right) st1.push(st2.top()->right);
                    if (st2.top()->left) st1.push(st2.top()->left);
                    st2.pop();
                }
            }
            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};