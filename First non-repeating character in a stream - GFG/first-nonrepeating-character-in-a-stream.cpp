// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// struct node {
//     char data;
//     node* left;
//     node* right;
//     node() {
//         data = '#';
//         left = right = NULL;
//     }
// };
// class Solution {
// 	public:
// 	    void debug(node* haha) {
// 	        return;
// 	        while(haha) { 
// 	            cout<<haha->data<<" "; 
// 	            haha = haha->right;
// 	        }
//             cout<<"\n";
// 	    }
//         string FirstNonRepeating(string str) {
//             //str = "ftvbwnimpvvbfvtot";
//             bool isDeleted[str.length()+1]; 
//             for(int i=0;i<str.length()+1;i++) isDeleted[i] = false;
//             // ffffffffffffttwww : expected
//             // ffffffffffffttbbb : actual
//             int n = str.length();
//             string ans = "";

//             map<char, node*> mp;
            
//             node* head = NULL;
//             node* tail = NULL;
            
//             for(int i=0;i<n;i++) {
//                 char ch = str[i];
//                 if (mp.find(ch) != mp.end()) {
//                     if (isDeleted[ch-'a']) {
                        
//                     } else {
//                         // if (!mp[ch]) continue;
//                         node* temp = mp[ch];
//                         if (temp->left == NULL && temp->right == NULL) {
//                             head = NULL; tail = NULL;
//                         } else if (temp->right == NULL) {
//                             tail = temp->left;
//                             tail->right = NULL;
//                         } else if (temp->left == NULL) {
//                             head = temp->right;
//                             head->left = NULL;
//                         } else {
//                             node* prev = temp->left;
//                             node* next = temp->right;
//                             prev->right = next;
//                             next->left = prev;
//                         }
//                         isDeleted[ch-'a'] = true;
//                         //mp[ch] = NULL;
//                     }
//                 } else {
//                     node* temp = new node();
//                     temp->data = ch;
//                     if (!head) head = temp;
//                     if (tail) {
//                         tail->right = temp;
//                         temp->left = tail;
//                     }
//                     tail = temp;
//                     mp[ch] = temp;
//                 }
//                 ans += head ? head->data : '#';
//                 debug(head);
//             }
//             return ans;
// 		}
// };

// ch = 'g'
// g e e k s f o r g e e k s
// g g g g g g g g k k k s f

// g: 2
// e: 2
// k: 1
// s: 1
// f: 1
// o: 1
// r: 1
 

#define MAX_CHAR 256


struct node {
    char a;
    struct node *next, *prev;
};
class Solution {
	public:
        void appendNode(struct node** head_ref,
                        struct node** tail_ref, char x)
        {
            struct node* temp = new node;
            temp->a = x;
            temp->prev = temp->next = NULL;
        
            if (*head_ref == NULL) {
                *head_ref = *tail_ref = temp;
                return;
            }
            (*tail_ref)->next = temp;
            temp->prev = *tail_ref;
            *tail_ref = temp;
        }
        
        // A utility function to remove a node 'temp' from DLL.
        // Note that the function may change the head and tail pointers,
        // that is why pointers to these pointers are passed.
        void removeNode(struct node** head_ref,
                        struct node** tail_ref, struct node* temp)
        {
            if (*head_ref == NULL)
                return;
        
            if (*head_ref == temp)
                *head_ref = (*head_ref)->next;
            if (*tail_ref == temp)
                *tail_ref = (*tail_ref)->prev;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
        
            delete (temp);
        }
        
        string FirstNonRepeating(string stream)
        {
            // inDLL[x] contains pointer to
            // a DLL node if x is present
            // in DLL. If x is not present, then inDLL[x] is NULL
            struct node* inDLL[MAX_CHAR];
        
            // repeated[x] is true if x is repeated two or more
            // times. If x is not seen so far or x is seen only
            // once. then repeated[x] is false
            bool repeated[MAX_CHAR];
        
            // Initialize the above two arrays
            struct node *head = NULL, *tail = NULL;
            for (int i = 0; i < MAX_CHAR; i++) {
                inDLL[i] = NULL;
                repeated[i] = false;
            }
        
            // Let us consider following stream and see the process
            // char stream[] = "geeksforgeeksandgeeksquizfor";
            string ans = "";
            for (int i = 0; i<stream.length(); i++) {
                char x = stream[i];
                // cout << "Reading " << x << " from stream \n";
        
                // We process this character only if it has not
                // occurred or occurred only once. repeated[x] is
                // true if x is repeated twice or more.s
                if (!repeated[x]) {
                    // If the character is not in DLL, then add this
                    // at the end of DLL.
                    if (inDLL[x] == NULL) {
                        appendNode(&head, &tail, stream[i]);
                        inDLL[x] = tail;
                    }
                    else // Otherwise remove this character from DLL
                    {
                        removeNode(&head, &tail, inDLL[x]);
                        inDLL[x] = NULL;
                        repeated[x]
                            = true; // Also mark it as repeated
                    }
                }
        
                // Print the current first non-repeating character
                // from stream
                // if (head != NULL)
                //     cout << "First non-repeating character so far "
                //             "is "
                //          << head->a << endl;
                ans += head ? head->a : '#';
            }
            return ans;
        }
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends