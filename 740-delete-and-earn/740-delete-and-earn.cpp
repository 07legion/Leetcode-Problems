class Solution {
private:
    vector<pair<int, int> > vect;
    vector<int> dp;
public:
    int func(int i) {
        if (i >= vect.size()) {
            return 0;
        }
        if (dp[i] != -1) return dp[i];
        if (i + 1 < vect.size() && vect[i].first + 1 == vect[i+1].first) {
            return dp[i] = max(vect[i].first * vect[i].second + func(i + 2), func(i+1));
        }
        else return dp[i] = vect[i].first * vect[i].second + func(i+1);
    }
    int deleteAndEarn(vector<int>& v) {
        if (v.size() == 1) return v[0];
        map<int, int> mp;
        for(auto it:v) {
            mp[it]++;
        }
        for(auto it:mp) vect.push_back({it.first, it.second});
        if (vect.size() == 1) return vect[0].first * vect[0].second;
        dp.resize(vect.size(), -1);
        return func(0);
    }
};