class Solution {
public:
    bool parseBoolExpr(string str) {
        int n = str.length();
        stack<char> st;
        for(int i=0;i<n;i++) {
            char ch = str[i];
            if (ch == '!' || ch == '&' || ch == '|' || ch == '(' || ch == 'f' || ch == 't') {
                st.push(ch);
            } else if (ch == ')') {
                vector<char> v; 
                while(!st.empty() && st.top() != '(') {
                    v.push_back(st.top());
                    st.pop();
                }
                if (st.top() == '(') st.pop();
                char ans = ' ';
                for(auto it:v) {
                    if (ans == ' ') ans = it;
                    else {
                        if (st.top() == '&') {
                            if (ans == 'f' || it == 'f') ans = 'f';
                            else ans = 't';
                        } else if (st.top() == '|') {
                            if (ans == 't' || it == 't') ans = 't';
                            else ans = 'f';
                        }                        
                    }
                }
                if (st.top() == '!') {
                    if (v[0] == 'f') ans = 't';
                    else ans = 'f';
                }
                st.pop();
                st.push(ans);
            }
        }
        if (st.top() == 'f') return false;
        return true;
    }
};

