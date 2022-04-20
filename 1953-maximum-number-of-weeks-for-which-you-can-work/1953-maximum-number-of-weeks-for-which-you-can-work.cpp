typedef long long int ll;
class Solution {
public:
    long long numberOfWeeks(vector<int>& v) {
        int n = v.size(); 
        ll sm = 0, mx = INT_MIN;
        for(int i=0;i<n;i++) mx = max(mx, ll(v[i])), sm += v[i];
        ll rest = sm - mx;
        if (mx > rest) return 2 * rest + 1;
        else return sm;
    }
}; 