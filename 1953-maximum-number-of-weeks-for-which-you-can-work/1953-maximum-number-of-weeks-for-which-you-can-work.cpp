typedef long long int ll;
class Solution {
public:
    long long numberOfWeeks(vector<int>& v) {
        ll sm = 0, mx = INT_MIN;
        for(int i=0;i<v.size();i++) sm += v[i], mx = max(mx, ll(v[i]));
        ll rest = sm - mx;
        if (mx > rest) {
            return 2 * rest + 1;
        }
        return sm;
    }
}; 