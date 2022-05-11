class Solution {
private:
    string str;
    int dp[6][51];
public:
    int func(int i, int ct) {
        if (ct == 0 && i == str.length()) return 1;
        if (i == str.length()) return 0;
        if (dp[i][ct] != -1) return dp[i][ct];
        if (ct == 0) return dp[i][ct] = func(i+1, ct);
        return dp[i][ct] = func(i, ct-1) + func(i+1, ct);
    }
    int countVowelStrings(int ct) {
        str = "aeiou";
        memset(dp, -1, sizeof dp);
        return func(0, ct);
    }
};