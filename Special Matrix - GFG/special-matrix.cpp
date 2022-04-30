// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    int mod;
    set<pair<int, int> > mp;
    int dp[501][501];
    int n, m;
public:
    int func(int i, int j) {
        if (i >= n || j >= m || mp.find({i, j}) != mp.end()) 
            return 0;
        if (i == n-1 && j == m-1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (func(i+1, j) % mod + func(i, j+1) % mod) % mod;
    }
	int FindWays(int N, int M, vector<vector<int>>v){
	    n = N; m = M; mod = 1e9 + 7;
        for(auto it:v) {
            mp.insert({it[0]-1, it[1]-1});
        }
        memset(dp, -1, sizeof dp);
        return func(0, 0);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends