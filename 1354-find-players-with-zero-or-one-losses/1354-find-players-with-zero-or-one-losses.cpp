class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& v) {
        vector<vector<int> > ans;
        map<int, int> mp;
        for(auto it:v) {
            mp[it[1]]++;
        }
        set<int> a, b;
        for(auto it:v) {
            if (mp.find(it[0]) == mp.end()) {
                a.insert(it[0]);
            }
            if (mp.find(it[1]) != mp.end() && mp[it[1]] == 1) {
                b.insert(it[1]);
            }
        }
        ans.push_back(vector<int> (a.begin(), a.end()));
        ans.push_back(vector<int> (b.begin(), b.end()));
        return ans;
    }
};