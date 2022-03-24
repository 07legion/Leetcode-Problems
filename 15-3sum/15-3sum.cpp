class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int> > ans;
        int n = v.size();
        sort(v.begin(), v.end());
        for(int i=0;i<n-2;i++) {
            if (i && v[i] == v[i-1]) continue;
            int low = i+1, high = n - 1;
            while(low < high) {
                if (v[low] + v[high] + v[i] == 0) {
                    ans.push_back({v[i], v[low], v[high]});
                    while(low + 1 < n && v[low] == v[low + 1]) low++;
                    while(high - 1 >= 0 && v[high] == v[high-1]) high--;
                    low++; high--;
                }
                else if (v[low] + v[high] + v[i] < 0) low++;
                else high--;
            }
        }
        return ans;        
    }
};