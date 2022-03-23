class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack<pair<char, int> > st;
        int n = str.length();
        for(int i=0;i<n;i++) {
            if (st.empty()) {
                st.push({str[i], 1});
            } else {
                if (st.top().first == str[i]) {
                    if (st.top().second + 1 < k) {
                        pair<char, int> p = st.top(); st.pop();
                        p.second += 1;
                        st.push(p);
                    } else {
                        st.pop();
                    }
                } else {
                    st.push({str[i], 1});
                }
            }
        }
        string ans = "";
        while(!st.empty()) {
            for(int j=0;j<st.top().second;j++) ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};