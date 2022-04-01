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
    vector<int> pre, in;
    int n, a;
public:
    node* func(int start, int end) {
        if (start > end) return NULL;
        node* root = new node();
        for(int j=start;j<=end;j++) {
            if (in[j] == pre[a]) {
                root->val = pre[a++];
                root->left = func(start, j-1);
                root->right = func(j+1, end);
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& pre1, vector<int>& in1) {
        in = in1; pre = pre1;
        n = in.size();
        a = 0;
        return func(0, n-1);
    }
};