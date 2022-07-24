class Solution {
private:
    
    vector<vector<int> > dp;
    vector<vector<int> > v;
    int n, m;
    bool isValidIndex(int x, int y, int currentCellValue) {
        if (x < 0 || y < 0 || x >= n || y >= m) return false;
        return currentCellValue < v[x][y];
    }
    
    int findLongestIncreasingPath(int x, int y) {
        if (dp[x][y] != -1) return dp[x][y];
        int a = 0, b = 0, c = 0, d = 0, ans = 1;
        if (isValidIndex(x+1, y, v[x][y])) {
            a = 1 + findLongestIncreasingPath(x+1, y);
        }
        if (isValidIndex(x, y+1, v[x][y])) {
            b = 1 + findLongestIncreasingPath(x, y+1);
        }
        if (isValidIndex(x-1, y, v[x][y])) {
            c = 1 + findLongestIncreasingPath(x-1, y);
        }
        if (isValidIndex(x, y-1, v[x][y])) {
            d = 1 + findLongestIncreasingPath(x, y-1);
        }
        ans = max({ans, a, b, c, d});
        return dp[x][y] = ans;
        
        //           --------- BFS doesn't work ---------
        // queue<pair<pair<int, int>, int> > q;
        // q.push({{startRowIndex, startColIndex}, 0});
        // vector<vector<int> > visited(rows, vector<int> (cols, -1));
        // int maxLength = 0;
        // while(!q.empty()) {
        //     int x = q.front().first.first, y = q.front().first.second, level = q.front().second;
        //     q.pop();
        //     if (visited[x][y] != -1 && level < visited[x][y]) {
        //         continue;
        //     }
        //     // cout<<x<<" "<<y<<" "<<level<<"\n";
        //     maxLength = max(maxLength, level);
        //     visited[x][y] = level;
        //     if (isValidIndex(x+1, y, rows, cols, v[x][y], v)) {
        //         // cout<<"\n1\n";
        //         q.push({{x+1, y}, level + 1});
        //     }
        //     if (isValidIndex(x-1, y, rows, cols, v[x][y], v)) {
        //         // cout<<"\n2\n";
        //         q.push({{x-1, y}, level + 1});
        //     }
        //     if (isValidIndex(x, y-1, rows, cols, v[x][y], v)) {
        //         // cout<<"\n3\n";
        //         q.push({{x, y-1}, level + 1});
        //     }
        //     if (isValidIndex(x, y+1, rows, cols, v[x][y], v)) {
        //         // cout<<"\n4\n";
        //         q.push({{x, y+1}, level + 1});
        //     }
        //     // cout<<q.size()<<"\n";
        // }
        // return maxLength;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& V) {
        v = V;
        n = v.size(); m = v[0].size();
        
        for(int i=0;i<n;i++) {
            vector<int> allNegatives;
            for(int j=0;j<m;j++) allNegatives.push_back(-1);
            dp.push_back(allNegatives);
        }
        
        int maxLen = 1;        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                maxLen = max(maxLen, findLongestIncreasingPath(i, j));
            }
        }
        return maxLen;
    }
};