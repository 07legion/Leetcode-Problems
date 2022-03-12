// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
// using node = Node;
// class Solution{
//   private:
//     map<node*, int> mp;
//   public:
//     int func(node* root) {
//         if (!root) return 0;
        
//         if (mp.find(root) != mp.end()) return mp[root];
        
//         int a = root->data;
//         if (root->left)
//             a += func(root->left->left) + func(root->left->right);
//         if (root->right)
//             a += func(root->right->right) + func(root->right->right);
        
//         int b = 0;
//         b += func(root->left) + func(root->right);
        
//         return mp[root] = max(a, b);
//     }
//     int getMaxSum(Node *root)  {
//         return func(root);
//     }
// };

// --

class Solution{
  public:
int sumOfGrandChildren(Node* node, map<Node*, int>& mp);
int getMaxSum(Node* node);
int getMaxSumUtil(Node* node, map<Node*, int>& mp);
};
  int Solution::sumOfGrandChildren(Node* node, map<Node*, int>& mp)
{
    int sum = 0;
 
    //  call for children of left child only if it is not NULL
    if (node->left)
        sum += getMaxSumUtil(node->left->left, mp) +
               getMaxSumUtil(node->left->right, mp);
 
    //  call for children of right child only if it is not NULL
    if (node->right)
        sum += Solution::getMaxSumUtil(node->right->left, mp) +
               Solution::getMaxSumUtil(node->right->right, mp);
 
    return sum;
}
 
//  Utility method to return maximum sum rooted at node 'node'
int Solution::getMaxSumUtil(Node* node, map<struct Node*, int>& mp)
{
    if (node == NULL)
        return 0;
 
    // If node is already processed then return calculated
    // value from map
    if (mp.find(node) != mp.end())
        return mp[node];
 
    //  take current node value and call for all grand children
    int incl = node->data + Solution::sumOfGrandChildren(node, mp);
 
    //  don't take current node value and call for all children
    int excl = Solution::getMaxSumUtil(node->left, mp) +
               Solution::getMaxSumUtil(node->right, mp);
 
    //  choose maximum from both above calls and store that in map
    mp[node] = max(incl, excl);
 
    return mp[node];
}
 
// Returns maximum sum from subset of nodes
// of binary tree under given constraints
int Solution::getMaxSum(Node* node)
{
    if (node == NULL)
        return 0;
    map<struct Node*, int> mp;
    return Solution::getMaxSumUtil(node, mp);
}
// };
// --



// { Driver Code Starts.

// Driver code 
int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        cout<<ob.getMaxSum(root)<<endl;
  }
  return 0;
}  // } Driver Code Ends