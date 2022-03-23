class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        unordered_map<int, bool> mp;
        for(int i=0;i<n;i++) {
            mp[v[i]] = true;
        }
        for(int i=0;i<n;i++) {
            if (mp.find(v[i]-1) == mp.end()) {
                int temp = v[i], a = 0;
                while(mp.find(temp) != mp.end()) {
                    temp++;
                    a++;
                }
                ans = max(ans, a);
            }
        }
        return ans;
    }
};