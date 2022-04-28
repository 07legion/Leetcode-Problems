// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private:
        vector<int> v;
        int dp[1001][1001];
    public:
    int func(int prev, int curr) {
        if (curr == v.size()) return 0;
        if (prev == -1) {
            return max(v[curr] + func(curr, curr+1), func(prev, curr+1));
        } else {
            if (dp[prev][curr] != -1) return dp[prev][curr];        
            if (v[curr] > v[prev]) {
                return dp[prev][curr] = max(v[curr] + func(curr, curr+1), func(prev, curr+1));
            }
            return dp[prev][curr] = func(prev, curr+1);
        }
    }
	int maxSumIS(int v1[], int n)  {  
	    memset(dp, -1, sizeof dp);
        for(int i=0;i<n;i++) v.push_back(v1[i]);
        return func(-1, 0);	    
        // vector<int> a(n, 0);
        // for(int i=0;i<n;i++) a[i] = v[i];
        // for(int i=1;i<n;i++) {
        //     for(int j=0;j<i;j++) {
        //         if (v[j] < v[i] && a[i] < a[j] + v[i]) {
        //             a[i] = a[j] + v[i];
        //         }
        //     }
        // }
        // int mx = INT_MIN;
        // for(int i=0;i<n;i++) mx = max(mx, a[i]);
        // return mx;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends