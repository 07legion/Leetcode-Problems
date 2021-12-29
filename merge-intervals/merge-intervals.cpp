class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        v.push_back({INT_MAX, INT_MIN});
        sort(v.begin(), v.end());
        vector<vector<int> > ans;
        int n = v.size();
        int low = v[0][0], high = v[0][1];
        // ans.push_back({low, high});
        for(int i=1;i<n;i++) {
            int a = v[i][0], b = v[i][1];
            if ((a >= low && a <= high) || (b >= low && b <= high)) {
                low = min({low, a, b});
                high = max({high, a, b});
            } else {
                ans.push_back({low, high});
                low = min(a, b);
                high = max(a, b);
            }
        }
        return ans;
    }
};