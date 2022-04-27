// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
    public:
    long long maxSubarraySum(int v[], int n){
        int mx = INT_MIN, curr = 0;
        int start = 0 , end = 0, s = 0;
        for(int i=0;i<n;i++) {
            if (curr + v[i] >= v[i]) {
                curr += v[i];
                start = s;
                end = i;
            } else {
                curr = v[i];
                s = i + 1;
            }
            mx = max(mx, curr);
        }
        return mx;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends