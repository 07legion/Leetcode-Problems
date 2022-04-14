class Solution {
private:
    int n;
    vector<string> v;
public:
    void func(int open, int close, string temp) {
        if (open == 0 && close == 0) {
            v.push_back(temp);
            return;
        }
        if (open)
            func(open-1, close, temp + "(");
        if (close && close > open)
            func(open, close-1, temp + ")");
    }
    vector<string> generateParenthesis(int N) {
        n = N;
        func(n, n, "");
        return v;
    }
};