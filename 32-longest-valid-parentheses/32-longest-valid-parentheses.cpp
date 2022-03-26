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
        return ans;
    }
};