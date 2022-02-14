class Solution {
private:
    map<pair<int, vector<int> >, int> mp;
public:
    int func(int i, vector<int>& v, vector<int>& wt, int slots) {
        if (i == v.size()) {
            return 0;
        }
        if (mp.find({i, wt}) != mp.end()) return mp[{i, wt}];
        int mx = INT_MIN;
        for(int j=1;j<=slots;j++) {
            if (wt[j] < 2) {
                wt[j]++;
                mx = max(mx, (j & v[i]) + func(i+1, v, wt, slots));
                wt[j]--;
            }
        }
        return mp[{i, wt}] = mx;
    }
    int maximumANDSum(vector<int>& v, int numSlots) {
        vector<int> wt (numSlots+1, 0);
        return func(0, v, wt, numSlots);
    }
};
