class Solution {
private:
    vector<int> v;
    int n;
    vector<int> dp;
public:
    bool func(int i) {
        if (i == n-1) return true;
        if (v[i] == 0) return false;
        bool a = false;
        if (dp[i] != -1) return dp[i];
        for(int j=1;j<=v[i];j++) {
            if (i + j < n)
                a |= func(i+j);
        }
        return dp[i] = a;
    }
    bool canJump(vector<int>& v1) {
        int mx = 0;
        for(int i=0;i<v1.size();i++) {
            if (mx < i) return false;
            mx = max(mx, i + v1[i]);
        }
        return true;
        // n = v1.size(); v = v1;
        // dp.resize(n, -1);
        // return func(0);
    }
};