class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.length(), ans = 0;
        int open = 0, close = 0;
        for(int i=0;i<n;i++) {
            if (str[i] == ')') close++;
            else open++;
            if (close == open) {
                ans = max(ans, close + open);
            } else if (open < close) open = 0, close = 0;
        }
        open = close = 0;
        for(int i=n-1;i>=0;i--) {
            if (str[i] == ')') close++;
            else open++;
            if (close == open) {
                ans = max(ans, close + open);
            } else if (open > close) open = 0, close = 0;
        }
        return ans;
    }
};