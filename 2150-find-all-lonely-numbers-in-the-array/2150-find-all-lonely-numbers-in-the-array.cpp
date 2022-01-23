class Solution {
public:
    vector<int> findLonely(vector<int>& v) {
        map<int, int> mp;
        for(int i=0;i<v.size();i++) {
            mp[v[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<v.size();i++) {
            if (mp[v[i]] == 1 && mp.find(v[i]-1) == mp.end() && mp.find(v[i]+1) == mp.end()) {
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};