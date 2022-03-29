class Solution {
public:
    int majorityElement(vector<int>& v) {
        
        // [2,2,1,1,1,2,2]
        int candidate = 0, count = 0, n = v.size();
        for(int i=0;i<n;i++) {
            if (count == 0) {
                candidate = v[i];
            }
            if (candidate == v[i]) count++;
            else count--;
        }
        count = 0;
        for(int i=0;i<n;i++) {
            if (v[i] == candidate) count++;
        }
        return count > n / 2 ? candidate : -1;
    }
};