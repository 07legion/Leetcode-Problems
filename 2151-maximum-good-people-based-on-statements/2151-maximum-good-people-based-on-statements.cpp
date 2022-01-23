class Solution {
private:
    int ans;
    vector<vector<int>> v;
public:
    bool valid(string str) {
        for(int i=0;i<v.size();i++) {
            if (str[i] == '1') {
                for(int j=0;j<v.size();j++) {
                    if (v[i][j] != 2 && v[i][j] != str[j] - '0') 
                        return false;
                }
            }
        }
        return true;
    }
    void func(int i, int n, int ct, string str) {
        if (i == n) {
            if (valid(str)) ans = max(ans, ct);
            return;
        }
        str.push_back('0');
        func(i+1, n, ct, str);
        str.pop_back();
        str.push_back('1');
        func(i+1, n, ct+1, str);
        str.pop_back();
    }
    int maximumGood(vector<vector<int>>& t) {
        v = t;
        ans = 0;
        func(0, v.size(), 0, "");
        return ans;
    }
};