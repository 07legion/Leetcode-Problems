class Solution {
private:
    vector<string> v;
    int n;
    unordered_map<string, bool> mp;
    unordered_map<string, bool> dp;
public:
    bool func(string word) {
        if (dp.find(word) != dp.end()) return dp[word];
        for(int i=1;i<word.length();i++) {
            string pre = word.substr(0, i);
            string suff = word.substr(i);
            if (mp[pre] == true && (mp[suff] == true || func(suff))) {
                dp[word] = true;
                return true;
            }
        }
        dp[word] = false;
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& V) {
        v = V; n = v.size();
        for(auto it:v) mp[it] = true;
        vector<string> ans;
        for(int i=0;i<n;i++) {
            if (func(v[i])) ans.push_back(v[i]);
        }
        return ans;
    }
};