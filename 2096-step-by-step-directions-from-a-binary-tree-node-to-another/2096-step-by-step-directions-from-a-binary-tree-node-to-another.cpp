class Solution {
public:
    TreeNode* getLCA(TreeNode* root, int start, int dest) {
        if(!root) return NULL;
        if(root->val == start || root->val == dest) return root;
        TreeNode* left = getLCA(root->left, start, dest);
        TreeNode* right = getLCA(root->right, start, dest);
        if(left && right) return root;
        return left ? left : right;
    }
    bool f(TreeNode* root, string& path, int val) {
        if (!root) return false;
        if (root->val == val) {
            return true;
        }
        bool a = f(root->left, path, val);
        if (a) path += 'L';
        bool b = f(root->right, path, val);
        if (b) path += 'R';
        return a || b;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* lca = getLCA(root, startValue, destValue);
        
        string lca_to_start = "", lca_to_dest = "";
        
        f(lca, lca_to_start, startValue);
        f(lca, lca_to_dest, destValue);        

        for(auto& c : lca_to_start) c = 'U';
        
        reverse(lca_to_dest.begin(), lca_to_dest.end());
        return lca_to_start + lca_to_dest;
    }
};