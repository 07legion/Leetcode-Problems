class Solution {
public:
    int trap(vector<int>& v) {
        
        int n = v.size();
        
        int i = 0, j = n-1;
        int lMax = -1, rMax = -1, ans = 0;
        
        while(i <= j) {
            if (v[i] <= v[j]) { 
                if (lMax < v[i]) lMax = v[i];
                else ans += lMax - v[i];
                i++;
            } else {
                if (rMax < v[j]) rMax = v[j];
                else ans += rMax - v[j];
                j--;
            }
        }
        return ans;
        
        
        // int n = v.size();
        // vector<int> left(n, v[0]), right(n, v[n-1]);
        // for(int i=1;i<n;i++) left[i] = max(left[i-1], v[i]);
        // for(int i=n-2;i>=0;i--) right[i] = max(right[i+1], v[i]);
        // int ans = 0;
        // for(int i=1;i<n-1;i++) {
        //     ans += min(left[i], right[i]) - v[i];
        // }
        // return ans;
    }
};


