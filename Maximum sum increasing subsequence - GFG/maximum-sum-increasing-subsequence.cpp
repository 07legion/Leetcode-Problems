// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	int maxSumIS(int v[], int n)  {  
        vector<int> a(n, 0);
        for(int i=0;i<n;i++) a[i] = v[i];
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if (v[j] < v[i] && a[i] < a[j] + v[i]) {
                    a[i] = a[j] + v[i];
                }
            }
        }
        int mx = INT_MIN;
        for(int i=0;i<n;i++) mx = max(mx, a[i]);
        return mx;
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