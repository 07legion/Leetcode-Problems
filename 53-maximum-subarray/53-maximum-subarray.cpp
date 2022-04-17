class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n = v.size();
        int currSum = 0, mx = INT_MIN;
        for(int i=0;i<n;i++) {
            if (currSum + v[i] > v[i]) {
                currSum += v[i];
            } else currSum = v[i];
            mx = max(mx, currSum);
        }
        return mx;
    }
};