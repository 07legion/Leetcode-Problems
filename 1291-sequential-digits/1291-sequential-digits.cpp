class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<string> q;
        vector<int> v;
        for(int i=1;i<=9;i++) q.push(to_string(i));
        while(!q.empty()) {
            string str = q.front(); q.pop();
            int a = stoi(str); 
            if (a >= low && a <= high) v.push_back(a);
            if (str.back() != '9')
                q.push(str + char(str.back() + 1));
        }
        return v;
    }
};