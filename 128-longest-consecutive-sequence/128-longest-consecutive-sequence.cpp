class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i=0;i<n;i++) mp[v[i]]++;
        for(int i=0;i<n;i++) {
            if (mp.find(v[i]-1) == mp.end()) {
                int j = v[i];
                while(mp.find(j) != mp.end()) {
                    j++;
                }
                ans = max(ans, j - v[i]);
            }
        }
        return ans;        
    }
};