class Solution {
private:
    int dp[101];
    string str;
public:
    int func(int i) {
        if (i == str.length()) return 1;
        if (str[i] == '0') return 0;
        
        if (dp[i] != -1) return dp[i];
        
        string temp2 = "";
        
        if (i+1 < str.length()) {
            temp2 += str[i];
            temp2 += str[i+1];
        }
        
        if (temp2 != "" && stoi(temp2) >= 1 && stoi(temp2) <= 26) {
            return dp[i] = func(i+1) + func(i+2);
        } else {
            return dp[i] = func(i+1);
        }
        
    }
    int numDecodings(string s) {
        str = s;
        memset(dp, -1, sizeof dp);
        return func(0);
    }
};