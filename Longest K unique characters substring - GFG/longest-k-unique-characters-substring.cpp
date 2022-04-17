// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string str, int k) {
        int n = str.length();
        map<char, int> mp;
        int i = 0, j = 0, ans = INT_MIN;
        while(j < n) {
            mp[str[j]]++;
            int sm = 0;
            for(auto it:mp) sm += it.second;
            if (mp.size() == k) {
                ans = max(ans, sm);
            }
            else if (mp.size() > k) {
                mp[str[i]]--; 
                if (mp[str[i]] == 0) mp.erase(str[i]);
                i++;
            }
            j++;
        }
        return ans == INT_MIN ? -1 : ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends