class Solution {
private:
    string str;
    string empty;
    unordered_map<string, bool> mp;
    map<pair<int, string>, bool> dp;
public:
    bool func(int i, string temp) {
        if (i == str.length()) {
            if (mp[temp]) return true;
            return false;
        }
        if (i >= str.length()) return false;
        if (dp.find({i, temp}) != dp.end()) return dp[{i, temp}];
        return dp[{i, temp}] = func(i+1, temp + str[i]) || (mp[temp] && func(i+1, empty + str[i]));
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it:wordDict) mp[it] = true;
        str = s;
        empty = "";
        return func(0, empty);
    }
};