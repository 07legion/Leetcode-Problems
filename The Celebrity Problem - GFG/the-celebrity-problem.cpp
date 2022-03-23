// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution  {
    public:
    int celebrity(vector<vector<int> >& v, int n)  {
        int i = 0, j = n - 1;
        while(i < j) {
            if (v[i][j]) {
                // i knows j
                i++;
            } else j--; // j knows i
        }
        int ans = i;
        for(int i=0;i<n;i++) {
            if (i == ans) continue;
            if (v[ans][i]) return -1;
            if (!v[i][ans]) return -1;
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
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends