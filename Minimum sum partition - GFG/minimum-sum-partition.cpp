// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    int dp[1002][1002];
    int n;
    vector<int> v;
public:
    bool func(int i, int target) {
        if (target == 0) return true;
        if (i == n) return false;
        if (dp[i][target] != -1) return dp[i][target];
        if (target - v[i] >= 0)
            return dp[i][target] = func(i+1, target - v[i]) || func(i+1, target);
        return dp[i][target] = func(i+1, target);
    }
    int minDifference(int a[], int N) {
        if (N == 1) return a[0];
        memset(dp, -1, sizeof dp);
        n = N;
        int sm = 0;
        for(int i=0;i<n;i++) {
            sm += a[i];
            v.push_back(a[i]);
        }
        int mn = INT_MAX;
        for(int i=1+sm/2;i>=0;i--) {
            if (func(0, i)) 
                mn = min(mn, abs(sm - 2 * i));
        }
        return mn;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends