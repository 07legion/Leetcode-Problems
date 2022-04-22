class Solution {
public:
    long long int power(long long int a, long long int b) {
        if (b == 0 || a == 1) return 1ll;
        if (b == 1) return a;
        if (a == 0) return 0ll;
        
        long long int p = power(a, b / 2);
        if (b % 2 == 0) return p * p;
        else return p * a * p;
    }
    int nextGreaterElement(int N) {
        string str = to_string(N);
        int n = str.length();
        int ind = -1;
        for(int i=n-1;i>=1;i--) {
            if (str[i] > str[i-1]) {
                ind = i-1;
                break;
            }
        }
        if (ind == -1) return -1;
        for(int i=n-1;i>=0;i--) {
            if (str[i] > str[ind]) {
                swap(str[ind], str[i]);
                reverse(str.begin() + ind + 1, str.end());
                break;
            }
        }
        long long int ans =  stoll(str);
        if (ans >= 0 && ans <= power(2, 31) - 1) return ans;
        return -1;
    }
};

// 5 3 6 9 7 4