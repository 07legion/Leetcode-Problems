// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
int vis[503][503];
int n, m;
int dx[8] = {-1, +1, 0, 0,  -1, -1, +1, +1};
int dy[8] = {0,  0, -1, +1, -1, +1, -1, +1};
vector<vector<char> > v;
public:
    void func(int i, int j) {
        vis[i][j] = true;
        // cout<<i<<" "<<j<<'\n';
        for(int p=0;p<8;p++) {
            int x = dx[p] + i;
            int y = dy[p] + j;
            // cout<<x<<" "<<y<<"\n";
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if (vis[x][y] == true || v[x][y] == '0') continue;
            // cout<<"hi\n";
            func(x, y);
        }
    }
    int numIslands(vector<vector<char>>& v1) {
        v = v1;
        n = v.size();
        m = v[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) vis[i][j] = false;
        }
        int ans = 0;
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[i].size();j++) {
                if (v[i][j] == '1' && vis[i][j] == false) {
                    func(i, j);
                    ans++;
                    // cout<<ans<<" nnn\n";
                    // return -1;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends