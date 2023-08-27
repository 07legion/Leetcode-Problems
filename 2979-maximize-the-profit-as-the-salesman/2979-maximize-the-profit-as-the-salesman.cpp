class Solution {
private:
    vector<vector<int> > v;
    // map<pair<int, int> , int> mp;
    unordered_map<int, int> mp;
    vector<int> temp;
    int n;
public:
    // int func(int i, int prev) {
    //     if (i == n) return 0;
    //     if (mp.find({i, prev}) != mp.end()) 
    //         return mp[{i, prev}];
    //     if (prev == -1) {
    //         return mp[{i, prev}] = max(v[i][2] + func(i+1, i), func(i+1, prev));
    //     } else {
    //         if (v[prev][1] < v[i][0]) {
    //             return mp[{i, prev}] = max(v[i][2] + func(i+1, i), func(i+1, prev));
    //         } else {
    //             return mp[{i, prev}] = func(i+1, prev);
    //         }
    //     }
    // }

    int func(int i) {
        if (i >= n || i < 0) return 0;
        if (mp.find(i) != mp.end()) return mp[i];
        int index = upper_bound(temp.begin(), temp.end(), v[i][1]) - temp.begin();
        return mp[i] = max(v[i][2] + func(index), func(i+1));
    }

    int maximizeTheProfit(int N, vector<vector<int>>& offers) {
        v = offers;
        n = offers.size();
        mp.clear(); temp.clear();
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++) {
            temp.push_back(v[i][0]);
        }
        return func(0);
    }
};



// n = 5, offers = [[0,0,1],[0,2,10],[1,3,2]]


// 0, 0  1
// 0, 2  2
// 1, 3  2