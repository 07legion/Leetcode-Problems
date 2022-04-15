class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int> > ans;
        sort(v.begin(), v.end());
        int n = v.size();
        for(int i=0;i<n;i++) {
            int j = i;
            int mn = v[j][0], mx = v[j][1];
            while(j < n && mx >= v[j][0]) {
                mn = min(mn, v[j][0]);
                mx = max(mx, v[j][1]);
                j++;
            }
            i = j-1;
            ans.push_back({mn, mx});
        }
        return ans;
    }
};