class Solution {
public:
    string removeDuplicateLetters(string str) {
        stack<char> st;
        string ans = ""; map<char, int> mp;
        int n = str.length();
        for(int i=0;i<n;i++) {
            mp[str[i]]++;
        }
        vector<bool> vis(26, false);
        for(int i=0;i<n;i++) {
            if (st.empty()) {
                if (vis[str[i]-'a'] == false) {
                    st.push(str[i]);
                    vis[str[i]-'a'] = true;
                }
            } else {
                if (vis[str[i]-'a'] == false) {
                    while (!st.empty() && st.top() >= str[i] && mp[st.top()] > 0) {
                        vis[st.top()-'a'] = false;
                        st.pop();
                    }
                    st.push(str[i]);
                    vis[str[i]-'a'] = true;
                }
            }
            mp[str[i]]--;
        }
        while(!st.empty()) ans += st.top(), st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// cbacdcbc


