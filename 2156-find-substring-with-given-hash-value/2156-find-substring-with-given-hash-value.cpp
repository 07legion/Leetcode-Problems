class Solution {
public:
    string subStrHash(string str, long long power, long long mod, long long k, int hashValue) {
        int n = str.length(), low = str.length();
        long long hash = 0, pr = 1;
        for(int i=n-1;i>=0;i--) {
            hash = ((hash * power) % mod + (str[i] - 'a' + 1)) % mod;
            if (i+k >= n) {
                pr = (pr * power) % mod;
            }
            else {
                hash = (hash - ((str[i+k] - 'a' + 1) * pr) % mod + mod) % mod;
            }
            if (hash == hashValue) {
                low = i;
            }
        }
        return str.substr(low, k);
    }
};