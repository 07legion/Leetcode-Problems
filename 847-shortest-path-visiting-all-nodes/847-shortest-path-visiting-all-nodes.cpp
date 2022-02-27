const long long int MAX = 1000000007;
class Solution {
private:
vector<vector<int> > v;
long long int dp[13][(1<<12)+1];
public:
    long long int func(int u, int mask) {
        if (dp[u][mask] != 0) return dp[u][mask];
        if (!(mask & (mask-1))) return 0;
        dp[u][mask] = MAX;
        for(auto it:v[u]) 
            if ((mask & (1 << it))) 
                dp[u][mask] = min(dp[u][mask], 1ll + min(func(it, mask), func(it, mask ^ (1 << u)))); 
            
        return dp[u][mask];
    }
    int shortestPathLength(vector<vector<int>>& v1) {
        v = v1; long long int ans = MAX;
        for(int i=0;i<v1.size();i++) 
            ans = min(ans, func(i, (1<<v.size())-1));
        return int(ans);
    }
};