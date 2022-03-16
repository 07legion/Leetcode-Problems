class Solution {
public:
    int calculate(string str) {
        str += '+';
        stack<int> st;
        int ans = 0, ct = 0;
        char op = '+';
        for(int i=0;i<str.length()+1;i++) {
            char ch = str[i];
            if (ch == ' ') continue;
            if (isdigit(ch)) {
                ct = (ct * 10) + (ch - '0');
            } else {
                // cout<<op<<" ";
                if (op == '+') st.push(ct);
                else if (op == '-') st.push(-ct);
                else if (op == '*') {
                    int a = st.top();
                    st.pop();
                    st.push(a * ct);
                } else if (op == '/') {
                    int a = st.top();
                    st.pop();
                    st.push(a / ct);
                } // else {
                //     assert(false);
                // }
                op = ch;
                // cout<<op<<" ";
                ct = 0;
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};