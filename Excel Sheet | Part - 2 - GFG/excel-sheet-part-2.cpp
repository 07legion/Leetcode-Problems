// { Driver Code Starts
//Initial template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    int ExcelColumnNumber(string s) {
        long long int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++) {
            ans *= 26;
            ans += (s[i] - 'A' + 1);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.ExcelColumnNumber(s)<<endl;
    }
}  // } Driver Code Ends