class Solution {
public:
    string removeDuplicates(string str) {
        string ans = "";
        for(int i=0;i<str.length();i++) {
            if (ans.back() == str[i]) ans.pop_back();
            else ans += str[i];
        }
        return ans;
    }
};