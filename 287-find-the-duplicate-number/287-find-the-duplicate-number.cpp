class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int slow = v[0];
        int fast = v[0];
        do {
            slow = v[slow];
            fast = v[v[fast]];
        } while(slow != fast);
        int entry = v[0];
        while(slow != entry) slow = v[slow], entry = v[entry];
        return slow;
    }
};