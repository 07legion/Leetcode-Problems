class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack<pair<char, int> > st;
        string ans = "";
        for(int i=0;i<str.length();i++) {
            if (st.empty()) {
                st.push({str[i], 1});
            } else {
                if (st.top().first == str[i]) {
                    st.top().second += 1;
                    if (st.top().second == k) {
                        st.pop();
                    }
                } else {
                    st.push({str[i], 1});
                }
            }
        }
        while(!st.empty()) {
            string temp = "";
            for(int i=0;i<st.top().second;i++) 
                temp += st.top().first;
            ans += temp;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};