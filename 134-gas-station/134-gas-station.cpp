class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tot = 0;
        for(int i=0;i<n;i++) {
            tot += gas[i] - cost[i];
        }
        if (tot < 0) return -1;
        int s = 0, sm = 0;
        for(int i=0;i<n;i++) {
            sm += gas[i] - cost[i];
            if (sm < 0) {
                s = i + 1;
                sm = 0;
            }
        }
        return s;
    }
};