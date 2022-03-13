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
    void f1(node* root, string& s) {
        if (!root) {
            s += ",#";
            return;
        }
        f1(root->left, s);
        s += "," + to_string(root->val);
        f1(root->right, s);
    }
    void f2(node* root, string& s) {
        if (!root) {
            s += ",#"; 
            return;
        };
        s += "," + to_string(root->val);
        f2(root->left, s);
        f2(root->right, s);
    }
    bool isSubtree(TreeNode* root1, TreeNode* root2) {
        if (!root2) return true;
        if (root1 == root2 && root1 == NULL) return true;
        if (!root1 && root2) return false;
        
        string s1 = "", s2 = "";
        // f1(root1, s1);
        // f1(root2, s2);
        // // cout<<s1<<" "<<s2<<"\n\n";
        // if (strstr(s1.c_str(), s2.c_str()) == NULL) return false;
        // s1 = ""; s2 = "";
        f2(root1, s1);
        f2(root2, s2);        
        // cout<<s1<<" "<<s2<<"\n\n";        
        return (strstr(s1.c_str(), s2.c_str()) != NULL);
    }
};