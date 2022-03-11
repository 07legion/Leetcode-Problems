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
            if (v[i][j]) i++; // i knows j
            else j--; // j knows i
        }
        int candidate = i;
        for(i=0;i<n;i++) {
            if (i == candidate) continue;
            if (v[candidate][i]) return -1;
            if (!v[i][candidate]) return -1;
        }
        return candidate;
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