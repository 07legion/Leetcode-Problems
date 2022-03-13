// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

using node = Node;
class Solution {
  public:
    void func(node* root, string& str) {
        if (!root) return;
        str += to_string(root->data);
        func(root->left, str);
        func(root->right, str);
    }
    // void f(node* root, string& str) {
    //     if (!root) return;
    //     f(root->left, str);
    //     str += to_string(root->data);
    //     f(root->right, str);
    // }
    void f2(node* root, string& s) {
        if (!root) {
            s += ",#"; 
            return;
        };
        s += "," + to_string(root->data);
        f2(root->left, s);
        f2(root->right, s);
    }    
    bool isSubTree(Node* root1, Node* root2) {
        if (root2 == NULL)
            return true;
        if (root1 == NULL)
            return false;        
        string s1 = "", s2 = "";
        // func(root1, s1);
        // func(root2, s2);
        // if (strstr(s1.c_str(), s2.c_str()) == NULL)
        //     return false;
        // s1 = "";
        // s2 = "";
        // f(root1, s1);
        // f(root2, s2);
        // if (strstr(s1.c_str(), s2.c_str()) == NULL)
        //     return false;
        // return true;
        f2(root1, s1);
        f2(root2, s2);        
        return (strstr(s1.c_str(), s2.c_str()) != NULL);        
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";

    }
    return 0;
}  // } Driver Code Ends