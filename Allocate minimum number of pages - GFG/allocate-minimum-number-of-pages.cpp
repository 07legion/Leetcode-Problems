// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution  {
private:
    int n, m;
public:
    bool check(int mid, int v[]) {
        int ct = 1; long long int sm = 0;
        for(int i=0;i<n;i++) {
            if (v[i] > mid) return false;
            if (sm + v[i] <= mid)  {
                sm += v[i];
            } else {
                sm = v[i];
                ct++;
            }
        }
        return ct <= m;
    }
    int findPages(int v[], int N, int M)  {
        n = N; m = M;
        if (n < m)
            return -1;        
        long long int sm = 0, ans = INT_MIN;
        for(int i=0;i<n;i++) sm += v[i];
        long long int low = 0, high = sm;
        while(low <= high) {
            long long int mid = low + (high - low) / 2;
            if (check(mid, v)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans == INT_MIN ? -1 : ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends