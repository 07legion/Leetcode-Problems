
class Solution {
public:
    long long numberOfWeeks(vector<int>& v) {
        int mx = *max_element(v.begin(), v.end());
        long long int sm = 0;
        for(int i=0;i<v.size();i++) sm += v[i];
        if (sm - mx >= mx) {
            return sm;
        } 
        return 2 * (sm - mx) + 1;
    }
};


