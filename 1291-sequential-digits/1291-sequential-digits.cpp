class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        queue<string> q;
        q.push("1");q.push("2");q.push("3");q.push("4");q.push("5");q.push("6");
        q.push("7");q.push("8");q.push("9");        
        while(!q.empty()) {
            string temp = q.front();
            if (stoi(temp) >= low && stoi(temp) <= high) {
                v.push_back(stoi(temp));
            }
            q.pop();
            char ch = temp.back();
            if (ch > '8') continue;
            temp.push_back(char(ch+1));
            q.push(temp);
        }
        return v;
    }
};