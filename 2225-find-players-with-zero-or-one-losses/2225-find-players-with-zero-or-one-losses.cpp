class Solution {
public:
    vector<vector<int> > findWinners(vector<vector<int>>& v) {
        map<int, int> mp;
        int n = v.size();
        for(int i=0;i<n;i++) {
            mp[v[i][1]]++;
        }
        vector<vector<int> > ans(2);
        set<int> used[2];
        for(int i=0;i<n;i++) {
            if (mp.find(v[i][0]) == mp.end() && used[0].find(v[i][0]) == used[0].end()) {
                ans[0].push_back(v[i][0]);
                used[0].insert(v[i][0]);
            }
            if (mp.find(v[i][1]) != mp.end()) {
                if (mp[v[i][1]] == 1 && used[1].find(v[i][1]) == used[1].end()) {
                    ans[1].push_back(v[i][1]);
                    used[1].insert(v[i][1]);
                }
            }
        }
        for(int i=0;i<2;i++) sort(ans[i].begin(), ans[i].end());
        return ans;
    }
};