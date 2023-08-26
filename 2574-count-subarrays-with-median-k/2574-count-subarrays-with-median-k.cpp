class Solution {
public:
    int countSubarrays(vector<int>& v, int k) {
        unordered_map<int, int> mp;
        int ans = 0, n = v.size(), index = 0;
        for(int i=0;i<n;i++) {
            if (v[i] == k) {
                index = i; break;
            }
        }
        int balance = 0;
        for(int i=index;i<n;i++) {
            if (v[i] < k) {
                balance--;
            } else if (v[i] > k) {
                balance++;
            }
            mp[balance]++;
        }
        balance = 0;
        for(int i=index;i>=0;i--) {
            if (v[i] < k) {
                balance--;
            } else if (v[i] > k) {
                balance++;
            }
            ans += mp[-balance] + mp[1-balance];
        }
        return ans;
    }
};
