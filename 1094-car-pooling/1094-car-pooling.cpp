class Solution {
public:
    // static bool cmp(const vector<int>& v1, const vector<int>& v2) {
    //     return (v1[1] < v2[1] || (v1[1] == v2[1] && v1[2] < v2[2]));
    // }
    bool carPooling(vector<vector<int>>& v, int capacity) {
        // sort(v.begin(), v.end(), cmp);
        // for(auto it:v) {
        //     for(auto it1:it) cout<<it1<<" "; cout<<"\n";
        // }
        vector<pair<int, int> > a, b;
        for(int i=0;i<v.size();i++) {
            a.push_back({v[i][1], v[i][0]});
            b.push_back({v[i][2], v[i][0]});
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int n = v.size();
        int i = 0, j = 0;
        int ans = 0, t = 0;
        while(i < n && j < n) {
            if (a[i].first < b[j].first) {
                t += a[i].second;
                i++;
            } else {
                t -= b[j].second;
                j++;
            }
            ans = max(ans, t);
        }
        return capacity >= ans;
    }
};