class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& v) {
        long long int ans = 0, n = v.size();
        for(int i=0;i<n;i++) v[i] %= 60;
        long long int ct = 0;
        map<long long int, long long int> mp;
        for(auto it:v) {
            mp[it]++;
            if (!it) ct++;
        }
        for(int i=0;i<n;i++) {
            if (mp.find(60 - v[i]) != mp.end()) {
                ans += mp[60 - v[i]];
            }
            if (v[i] == 60 - v[i]) ans--;
        }
        return ans / 2 + (ct * (ct - 1) / 2);
    }
};