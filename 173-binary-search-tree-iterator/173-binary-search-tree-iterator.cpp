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
    stack<node* > st;
public:
    void setNext(node* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        setNext(root);
    }
    int next() {
        node* temp = st.top();
        st.pop();
        setNext(temp->right);
        return temp->val;
    }
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */