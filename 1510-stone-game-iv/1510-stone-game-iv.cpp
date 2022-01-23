class Solution {
private:
    vector<long long int> v;
    int dp[2][100001];
public:
    bool func(int target, bool ch) {
        if (dp[ch][target] != -1) return dp[ch][target];
        int a = 0;
        for(auto it:v) {
            if (target >= it) {
                a |= !func(target-it, !ch);
                if (a > 0) break;
            }
        }        
        return dp[ch][target] = a;
    }
    bool winnerSquareGame(int n) {
        if (n == 1) return true;
        if (n == 2) return false;
        
        for(long long int i=1;i<=n;i++) {
            if (i * i > n) break;
            v.push_back(1ll*i*i);
        }
        memset(dp, -1, sizeof dp);
        return func(n, true);
    }
};