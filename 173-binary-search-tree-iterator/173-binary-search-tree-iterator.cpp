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
class BSTIterator {
private:
    vector<node* > v;
    int i;
public:
    void func(node* root) {
        if (!root) return;
        func(root->left);
        v.push_back(root);
        func(root->right);
    }
    BSTIterator(TreeNode* root) {
        i = 0;
        func(root);
    }    
    int next() {
        return v[i++]->val;
    }
    bool hasNext() {
        return i < v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */