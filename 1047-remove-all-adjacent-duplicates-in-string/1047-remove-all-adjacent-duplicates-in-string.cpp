class Solution {
public:
    string removeDuplicates(string str) {
        string ans = "";
        for(int i=0;i<str.length();i++) {
            if (str == "") ans += str[i];
            else {
                if (str[i] == ans.back()) {
                    ans.pop_back();
                } else ans += str[i];
            }
        }
        return ans;
    }
};