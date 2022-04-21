class Solution {
public:
    string maximumNumber(string str, vector<int>& v) {
        for(int i=0;i<str.length();i++) {
            if (v[str[i]-'0'] > str[i]-'0') {
                while(i < str.length() && v[str[i]-'0'] >= str[i]-'0') {
                    str[i] = v[str[i] - '0'] + '0';
                    i++;
                }
                break;
            }
        }
        return str;
    }
};