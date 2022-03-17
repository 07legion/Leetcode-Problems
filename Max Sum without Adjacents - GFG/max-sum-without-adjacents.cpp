// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findMaxSum(int *v, int n) {
	    if (n == 1) return v[0];
	    if (n == 2) return max(v[0], v[1]);
	    int first = v[0], second = max(v[0], v[1]), ans = 0;
	    for(int i=2;i<n;i++) {
            ans = max(v[i] + first, second);
            first = second;
            second = ans;
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends