// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


typedef long long int ll;

class Solution {
private:
    string str;
    int n;
    ll dp[10009];
    ll MOD = 1e9 + 7;
public:

    ll func(int i) {
        if (i == n) return 1;
        if (dp[i] != -1) return dp[i];
        if (str[i] == '0') return 0;
        if (i+1 < n) {
            string temp = ""; temp += str[i];  temp += str[i+1];
            if(stoi(temp) >= 1 && stoi(temp) <= 26) 
                return dp[i] = (func(i+1) + func(i+2)) % MOD;
            else return dp[i] = func(i+1) % MOD;
        } else {
            return dp[i] = func(i+1) % MOD;
        }
    }
	int CountWays(string s) {
	    str = s; n = str.length();
	    memset(dp, -1, sizeof dp);
        return int(func(0) % MOD);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends