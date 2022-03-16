// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int> > v;
        for(int i=0;i<n;i++) {
            v.push_back({end[i], i});
        }
        sort(v.begin(), v.end());
        int ans = 1;
        int limit = v[0].first;
        for(int i=1;i<v.size();i++) {
            if (limit < start[v[i].second]) {
                ans++;
                limit = v[i].first;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends