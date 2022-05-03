class Solution {
private:
    string str;
    int n;
    int dp[2001];
public:
    bool check(int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        while(i < j) {
            if (str[i] != str[j]) return false;
            i++; j--;
        }
        return true;
    }
    int func(int i) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = 0,  mn = INT_MAX;
        for(int j=i;j<n;j++) {
            if (check(i, j)) {
                mn = min(mn, 1 + func(j+1));
            }
        }
        return dp[i] = mn;
    }
    int minCut(string s) {
        str = s; n = s.length();
        memset(dp, -1, sizeof dp);
        int ans = func(0);
        return ans == INT_MAX ? -1 : ans-1;
    }
};