// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&v, int n) {
        int ans = 0;
        vector<int> pre(n, v[0]);
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + v[i];
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) {
            if (mp.find(pre[i]) == mp.end()) {
                mp[pre[i]] = i;
            } else {
                ans = max(ans, i - mp[pre[i]]);
            }
            if (pre[i] == 0) ans = max(ans, i + 1);
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
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends