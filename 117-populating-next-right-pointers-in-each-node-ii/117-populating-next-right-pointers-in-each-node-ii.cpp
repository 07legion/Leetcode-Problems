/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

using node = Node;
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        node* leftmost = root;
        while(leftmost) {
            node* prev = NULL;
            node* curr = leftmost;
            leftmost = NULL;            
            while(curr) {
                if (curr->left) {
                    if (!prev) {
                        leftmost = curr->left;
                        prev = curr->left;
                    } else {
                        prev->next = curr->left;
                        prev = curr->left;
                    }
                }
                if (curr->right) {
                    if (!prev) {
                        leftmost = curr->right;
                        prev = curr->right;
                    } else {
                        prev->next = curr->right;
                        prev = curr->right;
                    }
                }
                curr = curr->next;
            }
        }
        return root;
    }
};