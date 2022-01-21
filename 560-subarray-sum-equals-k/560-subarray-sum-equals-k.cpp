class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        map<int, int> mp;
        int a = 0, ans = 0;
        mp[0] = 1;
        for(int i=0;i<v.size();i++) {
            a += v[i];
            ans += mp[a - k];
            mp[a]++;
        }
        return ans;
    }
};
