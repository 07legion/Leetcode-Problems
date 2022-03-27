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
            node* curr = leftmost;
            node* pre = NULL;
            leftmost = NULL;
            
            while(curr) {
                if (curr->left) {
                    if (!leftmost) leftmost = curr->left;
                    if (!pre) pre = curr->left;
                    else pre->next = curr->left, pre = pre->next;
                }
                if (curr->right) {
                    if (!leftmost) leftmost = curr->right;
                    if (!pre) pre = curr->right;
                    else pre->next = curr->right, pre = pre->next;
                }
                curr = curr->next;
            }
        }
        return root;
    }
};







