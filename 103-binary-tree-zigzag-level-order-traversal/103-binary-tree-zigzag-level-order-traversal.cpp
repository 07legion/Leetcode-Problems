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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<pair<TreeNode*, int> > st1; 
        stack<pair<TreeNode*, int> > st2;
        vector<vector<int> > res;
        if (!root) 
            return res;
        st1.push({root, 0});
        int i = 0;
        while(!st1.empty() || !st2.empty()) {
            vector<int> temp;
            if (i % 2) {
                while(!st2.empty()) {
                    temp.push_back(st2.top().first->val);
                    if (st2.top().first->right)
                        st1.push({st2.top().first->right, st2.top().second + 1});
                    if (st2.top().first->left)
                        st1.push({st2.top().first->left, st2.top().second + 1});
                    st2.pop();
                }
            } else {
                while(!st1.empty()) {
                    temp.push_back(st1.top().first->val);
                    if (st1.top().first->left) {
                        st2.push({st1.top().first->left, st1.top().second + 1});
                    }
                    if (st1.top().first->right)
                        st2.push({st1.top().first->right, st1.top().second + 1});
                    st1.pop();
                }
            }
            i++;
            res.push_back(temp);
        }
        return res;
    }
};