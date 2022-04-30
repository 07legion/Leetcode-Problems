class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.length();
        stack<pair<char, int> > st;
        int ans = 0;
        st.push({'.', -1});
        for(int i=0;i<n;i++) {
            if (str[i] == '(') {
                st.push({'(', i});
            } else {
                if (!st.empty() && st.top().first != '(') st.push({')', i});
                else {
                    if (!st.empty()) {
                        st.pop();
                        ans = max(ans, i - st.top().second);
                    }
                }
            }
        }
        // int mx = 0;
        // int open = 0, close = 0;
        // for(int i=0;i<n;i++) {
        //     if (str[i] == '(') open++;
        //     else close++;
        //     if (close > open) {
        //         open = close = 0;
        //     } else if (open == close) mx = max(mx, 2 * open);
        // }
        // open = close = 0;
        // for(int i=n-1;i>=0;i--) {
        //     if (str[i] == '(') open++;
        //     else close++;
        //     if (close < open) {
        //         open = close = 0;
        //     } else if (open == close) {
        //         mx = max(mx, 2 * open);
        //     }
        // }
        // return mx;
        return ans;
    }
};