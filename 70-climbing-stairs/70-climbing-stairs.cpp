class Solution {
private:
    vector<int> dp;
public:
    int func(int target) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (dp[target] != -1) return dp[target];
        return dp[target] = func(target - 1) + func(target - 2);
    }
    int climbStairs(int n) {
        // dp.resize(46, -1);
        // return func(n);
        if (n <= 3) return n;
        int f = 3, s = 2;
        for(int i=4;i<=n;i++) {
            int temp = f;
            f = f + s;
            s = temp;
        }
        return f;
    }
};