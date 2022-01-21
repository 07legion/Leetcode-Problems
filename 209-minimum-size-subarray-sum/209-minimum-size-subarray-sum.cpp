class Solution {
private:
    vector<int> pre;
public:
    int check(vector<int> v, int target, int a) {
        a--;
        for(int i=a;i<v.size();i++) {
            int right = i, left = i-a, sm = 0;
            if (!left) {
                sm = pre[right];
            } else sm = pre[right] - pre[left-1];
            if (sm >= target) return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& v) {
        int n = v.size(), ans = 0;
        pre.resize(n, 0);
        pre[0] = v[0];
        for(int i=1;i<v.size();i++) {
            pre[i] += pre[i-1] + v[i];
        }
        int low = 0, high = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (check(v, target, mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};