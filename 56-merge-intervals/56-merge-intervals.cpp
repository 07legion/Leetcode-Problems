class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        vector<vector<int> > ans;
        v.push_back({INT_MIN, INT_MIN});
        int mn, mx;
        for(int i=0;i<n+1;i++) {
            if (i == 0) {
                mn = v[i][0]; mx = v[i][1];
            } else {
                if ((v[i][0] >= mn && v[i][0] <= mx) || (v[i][1] >= mn && v[i][1] <= mx)) {
                    mn = min(mn, v[i][0]);
                    mx = max(mx, v[i][1]);
                } else {
                    ans.push_back({mn, mx});
                    mn = v[i][0]; mx = v[i][1];
                }
            }
        }
        return ans;
    }
};