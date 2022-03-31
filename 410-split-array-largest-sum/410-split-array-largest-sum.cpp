// class Solution {
// private:
//     int n, m;
//     vector<int> v;
//     // int dp[1002][1002];
//     unordered_map<string, int> mp;
// public:
//     int func(int i, int cut, int temp, int mx) {
//         if (i == n) {
//             cut++;
//             if (cut == m) {
//                 return max(mx, temp);
//             }
//             return INT_MAX;
//         }
//         // if (cut > m) return INT_MAX; 
//         // if (dp[i][cut] != -1) return dp[i][cut];
//         string s = to_string(i) + "haha" + to_string(cut) + "amis" + to_string(temp) + "shar" + to_string(mx) + "lol";
//         if (mp.find(s) != mp.end()) return mp[s];
//         if (cut < m) {
//             // return dp[i][cut][temp] = min(func(i+1, cut, temp + v[i], mx), func(i+1, cut+1, v[i], max(mx, temp)));
//             return mp[s] = min(func(i+1, cut, temp + v[i], mx), func(i+1, cut+1, v[i], max(mx, temp)));
//         } else {
//             // return dp[i][cut][temp] = func(i+1, cut, temp + v[i], mx);
//             return mp[s] = func(i+1, cut, temp + v[i], mx);            
//         }
//     }
//     int splitArray(vector<int>& V, int M) {
//         n = V.size();
//         // memset(dp, -1, sizeof dp);
//         m = M;
//         v = V;
//         return n;
//         // return func(0, 0, 0, INT_MIN);
//     }
// };
class Solution {
private:
    vector<int> v;
    int n, m;
public:
    int check(int sm) {
        int cuts = 0, curr = 0;
        for(int i=0;i<n;i++) {
            if (curr + v[i] <= sm) {
                curr += v[i];
            } else {
                curr = v[i];
                cuts++;
            }
        }
        return ++cuts;
    }
    int splitArray(vector<int>& V, int M) {
        v = V;
        n = v.size(); m = M;
        int ans = INT_MAX;
        int mx = INT_MIN, s = 0;
        for(auto it:v) {
            mx = max(mx, it);
            s += it;
        }
        int low = mx, high = s;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cuts = check(mid);
            if (cuts <= m) {
                ans = min(ans, mid);
                high = mid - 1;
            } else if (cuts > m) {
                low = mid + 1;
            }
        }
        return ans;
    }
};