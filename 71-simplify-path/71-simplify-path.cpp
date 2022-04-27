class Solution {
public:
    string simplifyPath(string str) {
        int n = str.length();
        stack<string> st;
        for(int i=0;i<n;i++) {
            int j = i+1;
            string temp = "/";
            while(j < n && str[j] != '/') {
                temp += str[j]; j++;
            }
            // cout<<temp<<"\n";
            if (temp != "" && temp != "/" && temp != "/.") {
                if (temp == "/..") {
                    if (!st.empty()) st.pop();
                } else st.push(temp);
            } 
            i = j-1;
        }
        string ans = "";
        vector<string> v;
        while(!st.empty()) {
            // cout<<st.top()<<" "; cout<<"\n";
            // ans += st.top();
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        for(auto it:v) ans += it;
        // reverse(ans.begin(), ans.end());
        if (ans.back() == '/') ans.pop_back();
        if (ans.front() != '/') ans = "/" + ans;
        return ans;
    }
};