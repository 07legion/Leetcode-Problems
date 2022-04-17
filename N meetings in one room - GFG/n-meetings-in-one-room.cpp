// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int> > v;
        for(int i=0;i<n;i++) v.push_back({end[i], i});
        sort(v.begin(), v.end());
        int last = v[0].first, ans = 1;
        for(int i=0;i<n;i++) {
            if (start[v[i].second] > last) {
                ans++;
                last = v[i].first;
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