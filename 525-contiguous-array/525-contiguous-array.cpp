class Solution {
public:
    int findMaxLength(vector<int>& v) {
        map<int, int> mp;
        int sm = 0, n = v.size(), ans = 0;
        for(int i=0;i<n;i++) {
            sm += v[i] == 0 ? -1 : 1;
            if (!sm) {
                ans = max(ans, i + 1);
            }
            else if (mp.find(sm) == mp.end()) {
                mp[sm] = i;
            } else {
                ans = max(ans, abs(i - mp[sm]));
            }
        }
        return ans;
    }
};