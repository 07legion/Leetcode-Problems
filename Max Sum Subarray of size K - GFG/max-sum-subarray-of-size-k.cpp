// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int k, vector<int> v , int n){
        vector<int> pre(n, 0);
        pre[0] = v[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + v[i];
        int mx = INT_MIN;
        int i = 0, j = k-1;
        while(j < n) {
            int sm = 0;
            if (i == 0) sm = pre[j];
            else sm = pre[j] - pre[i-1];
            mx = max(mx, sm);
            i++; j++;
        }
        return mx;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends