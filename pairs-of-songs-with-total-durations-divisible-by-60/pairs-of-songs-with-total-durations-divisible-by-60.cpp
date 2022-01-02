class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& v) {
        map<int, int> mp;
        int ct = 0;
        for(int i=0;i<v.size();i++) {
            v[i] %= 60; mp[v[i]]++;
            if (!v[i]) ct++;
        }
        int ans = 0, n = v.size();
        for(int i=0;i<n;i++) {
            if (mp.find(60-v[i]) != mp.end()) ans += mp[60 - v[i]];
            if (v[i] == 60-v[i]) ans--;
        }
        return ((ct * (ct - 1)) / 2) + ans / 2;
    }
};


// 30,20,150,100,40
// 30 20  30 40  40

// 20 30 30 40 40
