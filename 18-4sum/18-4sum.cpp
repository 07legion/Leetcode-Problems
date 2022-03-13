class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        vector<vector<int> > ans;
        int n = v.size();
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++) {
            if (i > 0 && v[i] == v[i-1]) continue;
            for(int j=i+1;j<n;j++) {
                if (j > i+1 && v[j] == v[j-1]) continue;
                int low = j+1, high = n-1;
                int t = target - v[i] - v[j];                
                while(low < high) {
                    if (v[low] + v[high] == t) {
                        ans.push_back({v[i], v[j], v[low], v[high]});
                        while(low < high && low + 1 < n && v[low] == v[low+1]) low++;
                        while(low < high && high-1 >= 0 && v[high] == v[high-1]) high--; 
                        low++;
                        high--;
                    } else if (v[low] + v[high] < t) low++;
                    else high--;
                }
            }
        }
        return ans;
    }
};