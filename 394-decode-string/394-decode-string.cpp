// 1st Approach
// class Solution {
// public:
//     string decodeString(string str) {   
//         string ans = "";
//         stack<string> st;
//         for(int i=0;i<str.length();i++) {
//             if (str[i] == ']') {
//                 string temp = "";
//                 while(!st.empty() && st.top() != "[") {
//                     temp += st.top();
//                     st.pop();
//                 } 
//                 reverse(temp.begin(), temp.end());
//                 if (!st.empty() && st.top() == "[") {
//                     st.pop();
//                     string aint = "";
//                     while(!st.empty() && st.top() != "" && st.top()[0] >= '0' && st.top()[0] <= '9') {
//                         aint += st.top()[0];
//                         st.pop();
//                     }
//                     reverse(aint.begin(), aint.end());
//                     if (aint != "") {
//                         int a = stoi(aint);
//                         string gg = "";
//                         for(int k=0;k<a;k++) {
//                             gg += temp;
//                         } 
//                         for(auto it:gg) {
//                             string h = "";
//                             h += it; st.push(h);
//                         }
//                     }
//                 }
//             } else {
//                 string t = "";
//                 t += str[i];
//                 st.push(t);
//             }
//         }
//         vector<string> v;
//         while(!st.empty()) ans += st.top(), st.pop();
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

// 2nd Approach
class Solution {
public:
    string decodeString(string str) {
        stack <char> st1;
        stack <int> st2;
        string ans = "";
        int n = str.length();
        for(int i=0;i<n;i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                int ct = 0;
                while(str[i] >= '0' && str[i] <= '9') {
                    ct = ct * 10 + (str[i] - '0');
                    i++;
                }
                i--;
                // cout<<ct<<"\n";
                st2.push(ct);
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                st1.push(str[i]);
            } else if (str[i] == '[') {
                if (i-1 >= 0 && (str[i-1] >= '0' && str[i-1] <= '9')) {
                    st1.push('[');
                } else {
                    st2.push(1);
                    st1.push('[');
                }
            } else {
                string temp = "", temp1 = "";
                while(!st1.empty() && st1.top() != '[') {
                    temp1 += st1.top();
                    st1.pop();
                }
                if (st1.top() == '[') st1.pop();
                reverse(temp1.begin(), temp1.end());
                int t = 0;
                if (!st2.empty()) {
                    t = st2.top(), 
                    st2.pop();
                }
                for(int j=0;j<t;j++) temp += temp1;
                for(int j=0;j<temp.length();j++) st1.push(temp[j]);
            }
        }
        while(!st1.empty()) ans += st1.top(), st1.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};