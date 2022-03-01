// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    private:
    vector<long long int> dp;
	public:
    long long int func(long long int target) {
        if (target == 0) return 1ll;
        if (target < 0) return 0ll;
        if (dp[target] != -1) return dp[target];
        return dp[target] = func(target - 1ll) + func(target - 2 * 1ll);
    }
		int nthPoint(int n){
        // dp.resize(30001, -1ll);
        // return int(func(n));
		    if(n==1 || n==2) return n;
		    
		   
		   long long int x=1;
		   long long int y=2;
		   long long int z,ans;
		   for(int i=3;i<=n;i++){
		       z=x%1000000007+y%1000000007;
		       z%=1000000007;
		       ans=z;
		       x=y;
		       y=z;
		   }
		   
		   return z;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends