class Solution {
public:
    int kthSmallest(vector<vector<int>>& v, int k) { 
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > > , greater<pair<int, pair<int, int> > > > pq;
        
        int n = v.size();
        for(int i=0;i<n;i++) {
            pq.push({v[i][0], {i, 0}});
        }
        int a = 1;
        while(!pq.empty()) {
            int value = pq.top().first;
            if (a == k) return value;
            auto [i, j] = pq.top().second;
            pq.pop();
            if (j + 1 < n)
                pq.push({v[i][j+1], {i, j+1}});
            a++;
        }
        return -1;
    }
};