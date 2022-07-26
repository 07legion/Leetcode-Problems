class Solution {
private:
    // vector<int> startTime, endTime, profit;
    vector<pair<pair<int, int> , int> > v;
    int dp[50001];
    // map<pair<int, int> , int> mp;
public:
    int func(int i, int prev) {
        if (i == -1 || i >= v.size()) {
           return 0; 
        }
        if (dp[i] != -1) return dp[i];
        int index = -1, low = i+1, high = v.size()-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid].first.first >= v[i].first.second) {
                index = mid; high = mid - 1;
            } else low = mid + 1;
        }
        // if (prev == -1) {
            // return mp[{i, prev}] = max(v[i].second + func(i+1, i), func(i+1, prev));
            return dp[i] = max(v[i].second + func(index, i), func(i+1, prev));
        // } else {
        //     if (v[i].first.first >= v[prev].first.second) {
        //         return mp[{i, prev}] = max(v[i].second + func(i+1, i), func(i+1, prev));
        //     } else {
        //         return mp[{i, prev}] = func(i+1, prev);
        //     }
        // }
    }
    int jobScheduling(vector<int>& S, vector<int>& E, vector<int>& P) {
        // startTime = S; endTime = E; profit = P;
        memset(dp, -1, sizeof dp);
        for(int i=0;i<S.size();i++) {
            v.push_back({{S[i], E[i]}, P[i]});
        }
        sort(v.begin(), v.end());
        return func(0, -1);
    }
};








// class Solution {
// private:
//     vector<int> startTime, endTime, profit;
//     vector<pair<pair<int, int> , int> > v;
//     // int dp[50001][50001];
//     map<pair<int, int> , int> mp;
// public:
//     int func(int i, int prev) {
//         if (i >= v.size()) {
//            return 0; 
//         }
//         if (mp.find({i, prev}) != mp.end()) return mp[{i, prev}];
//         if (prev == -1) {
//             return mp[{i, prev}] = max(profit[i] + func(i+1, i), func(i+1, prev));
//         } else {
//             if (startTime[i] >= endTime[prev]) {
//                 return mp[{i, prev}] = max(profit[i] + func(i+1, i), func(i+1, prev));
//             } else {
//                 return mp[{i, prev}] = func(i+1, prev);
//             }
//         }
//     }
//     int jobScheduling(vector<int>& S, vector<int>& E, vector<int>& P) {
//         startTime = S; endTime = E; profit = P;
//         // memset(dp, -1, sizeof dp);
//         for(int i=0;i<S.size();i++) {
//             v.push_back({{S[i], E[i]}, P[i]});
//         }
//         sort(v.begin(), v.end());
//         return func(0, -1);
//     }
// };