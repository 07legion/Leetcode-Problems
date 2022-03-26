class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int slow = 0;
        int fast = 0;
        do {
            slow = v[slow];
            fast = v[v[fast]];
        } while(slow != fast);
        int entry = 0;
        while(slow != entry) slow = v[slow], entry = v[entry];
        return slow;
    }
};