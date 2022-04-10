// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int> > v){
        int dp[n][m];
        for(int i=0;i<n;i++) dp[i][0] = v[i][0];
        for(int i=0;i<m;i++) dp[0][i] = v[0][i];
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if (v[i][j] == 1) 
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                else dp[i][j] = 0;
            }
        }
        int mx = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) mx = max(mx, dp[i][j]);
        }
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends