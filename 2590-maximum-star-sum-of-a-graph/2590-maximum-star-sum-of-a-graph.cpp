class Solution {
private:
    vector<int> v[100002];
    int k;
    vector<int> wt;
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int K) {
        
        k = K;
        wt = vals;

        for(int i=0;i<edges.size();i++) {
            int a = edges[i][0], b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        int ans = INT_MIN;

        for(int i=0;i<vals.size();i++) {
            priority_queue<int, vector<int> , greater<int> > pq;
            int temp = vals[i];
            
            for(auto it:v[i]) {
                pq.push(vals[it]);
                if (pq.size() > k) pq.pop();
            }

            while(!pq.empty()) {
                if (pq.top() > 0) temp += pq.top();
                pq.pop();
            }

            ans = max(ans, temp);
        }

        return ans;
    }
};
