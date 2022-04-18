// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
private:
    vector<int> v[501];
    vector<bool> vis;
public:
    void dfs(int u) {
        vis[u] = true;
        for(auto it:v[u]) {
            if (vis[it]) continue;
            dfs(it);
        }
    }
    int numProvinces(vector<vector<int> > isConnected, int n) {
        for(int i=0;i<isConnected.size();i++) {
            for(int j=0;j<isConnected[i].size();j++) {
                if (i == j) continue;
                if (isConnected[i][j] == 1) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        int ct = 0;
        vis.resize(isConnected.size()+1, false);
        for(int i=0;i<isConnected.size();i++) {
            if (!vis[i]) {
                dfs(i);
                ct++;
            }
        }
        return ct;
    }    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends