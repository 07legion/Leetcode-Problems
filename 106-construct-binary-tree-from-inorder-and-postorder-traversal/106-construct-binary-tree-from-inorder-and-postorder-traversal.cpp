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
    vector<int> in, post;
    map<int, int> mp;
public:
    node* func(int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return NULL;
        node* root = new node(post[postEnd]);
        int rootIndex = mp[post[postEnd]];
        int numsLeft = rootIndex - inStart;
        root->left = func(inStart, rootIndex-1, postStart, postStart + numsLeft-1);
        root->right = func(rootIndex+1, inEnd, postStart+numsLeft, postEnd-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in1, vector<int>& post1) {
        in = in1; post = post1;
        for(int i=0;i<in.size();i++) mp[in[i]] = i;
        return func(0, in.size()-1, 0, post.size()-1);
    }
};