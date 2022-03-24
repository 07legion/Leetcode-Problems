typedef long long int ll;
class Solution {
public:
    long long numberOfWeeks(vector<int>& v) {
        ll mx = INT_MIN, n = v.size(), sm = 0;
        for(int i=0;i<n;i++) sm += v[i], mx = max(mx, ll(v[i]));
        ll rest = sm - mx;
        if (rest < mx)
            return 2 * rest + 1;
        else return sm;
    }
}; 


