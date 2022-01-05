class Solution {
private:
    vector<vector<string> > v;
public:
    bool isValid(string str) {
        if (str == "") return false;
        int i = 0, j = str.length()-1;
        while(i <= j) {
            if (str[i] != str[j]) return false;
            i++; j--;
        }
        return true;
    }
    void func(int i, vector<string> temp, string str) {
        if (i >= str.length()) {
            v.push_back(temp);
            return;
        }
        for(int j=i;j<str.length();j++) {
            if (isValid(str.substr(i, j-i+1))) {
                temp.push_back(str.substr(i, j-i+1));
                func(j+1, temp, str);
                temp.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string str) {
        func(0, vector<string> {}, str);
        return v;
    }
};