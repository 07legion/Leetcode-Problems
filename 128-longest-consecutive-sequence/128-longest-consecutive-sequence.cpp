class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();
        unordered_map<int, bool> mp;
        for(int i=0;i<n;i++) {
            mp[v[i]] = true;
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if (mp.find(v[i]-1) == mp.end()) {
                int j = v[i], ct = 0;
                while(mp.find(j) != mp.end()) {
                    j++; ct++;
                }
                ans = max(ans, ct);
            }
        }
        return ans;
    }
};