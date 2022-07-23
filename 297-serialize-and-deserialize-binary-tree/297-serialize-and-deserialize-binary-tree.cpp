/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using node = TreeNode;
class Codec {
private:
    void levelOrderTraversal(node* root, string& inorder) {
        if (!root) return;
        queue<node* > q;
        q.push(root); inorder += to_string(root->val);
        inorder += ' ';
        while(!q.empty()) {
            node* currentNode = q.front();
            q.pop();
            if (currentNode->left) {
                q.push(currentNode->left);
                inorder += to_string(currentNode->left->val);
            } else {
                inorder += '#';
            }
            inorder += ' ';
            if (currentNode->right) {
                q.push(currentNode->right);
                inorder += to_string(currentNode->right->val);
            } else {
                inorder += '#';
            }
            inorder += ' ';
        }
    }
public:

    string serialize(TreeNode* root) {
        string inorder = "";
        levelOrderTraversal(root, inorder);
        return inorder;
    }
    int get(int& i, string data) {
        string number = "";
        while(i < data.length() && data[i] != ' ') {
            number += data[i++];
        }
        i++;
        return stoi(number);
    }
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        int i = 0;
        node* root = new node(get(i, data));
        queue<node* > q; q.push(root);
        while(!q.empty()) {
            node* currentNode = q.front();
            q.pop();
            if (data[i] == '#') {
                i += 2;
            } else {
                currentNode->left = new node(get(i, data));
                q.push(currentNode->left);
            }
            if (data[i] == '#') {
                i += 2;
            } else {
                currentNode->right = new node(get(i, data));
                q.push(currentNode->right);
            }
        }
        return root;
    }
};

// 1 2 3 N N 4 5 N N N N 


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));