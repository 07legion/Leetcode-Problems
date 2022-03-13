// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string str){
        string ans = "";
        stack<string> st;
        for(int i=0;i<str.length();i++) {
            if (str[i] == ']') {
                string temp = "";
                while(!st.empty() && st.top() != "[") {
                    temp += st.top();
                    st.pop();
                } 
                reverse(temp.begin(), temp.end());
                if (!st.empty() && st.top() == "[") {
                    st.pop();
                    string aint = "";
                    while(!st.empty() && st.top() != "" && st.top()[0] >= '0' && st.top()[0] <= '9') {
                        aint += st.top()[0];
                        st.pop();
                    }
                    reverse(aint.begin(), aint.end());
                    if (aint != "") {
                        int a = stoi(aint);
                        string gg = "";
                        for(int k=0;k<a;k++) {
                            gg += temp;
                        } 
                        for(auto it:gg) {
                            string h = "";
                            h += it; st.push(h);
                        }
                    }
                }
            } else {
                string t = "";
                t += str[i];
                st.push(t);
            }
        }
        vector<string> v;
        while(!st.empty()) ans += st.top(), st.pop();
        // reverse(v.begin(), v.end());
        // for(auto it:v) ans += it;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends