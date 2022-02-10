class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();
        vector<int> pre(n, 0);
        int ans = 0;
        pre[0] = v[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + v[i];
        // int low = 0, high = 0;
        // // for(auto it:pre) cout<<it<<" "; cout<<"\n";
        // while(low < n && high < n) {
        //     int sm = 0;
        //     if (low == 0) sm += pre[high];
        //     else sm += pre[high] - pre[low-1];
        //     // cout<<low<<" "<<high<<" "<<sm<<"\n";
        //     if (sm >= k) {
        //         if (sm == k)
        //             ans++;
        //         low++;
        //     } else {
        //         high++;
        //     }
        //     if (low > high) high = low;
        // }
        map<int, int> mp;
        mp[0] = true;
        for(int i=0;i<n;i++) {
            if (mp[pre[i]-k]) {
                ans += mp[pre[i]-k];
            }
            mp[pre[i]]++;
        }
        return ans;
    }
};
