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
    int ans;
public:
    void func(node* root, stack<char> st){
        if (root && !root->left && !root->right) {
            if (root->val) st.push('1');
            else st.push('0');
            int t = 1, a = 0;
            while(!st.empty()) {
                if (st.top() == '1') a += t;
                t *= 2;
                st.pop();
            }
            ans += a;
            // cout<<str<<" "<<a<<"\n";
            return;
        }
        if (root) {
            if (root->val) st.push('1');
            else st.push('0');
            func(root->left, st);
            func(root->right, st);
            st.pop();
        }
    }
    int sumRootToLeaf(node* root) {
        if(!root) return 0;
        stack<char> st;
        func(root, st);
        return ans;
    }
};


// [1,0,1,0,1,0,1]
// [0]
// [1,0,0,0,0,0,0]
// [0,0,0]
// [1]
// [1,1,1,0,0]