class Solution {
public:
    int majorityElement(vector<int>& v) {
        
        // [2,2,1,1,1,2,2]
        int ct = 0, ans = -1;        
        for(auto it:v) {
            if (ct == 0) {
                ans = it;
            }
            if (it == ans)
                ct += 1;
            else ct -= 1;
        }
        return ans;
    }
};