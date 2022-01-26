class Solution {
    int ans = 0;
    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        int n = values.length;
        List<Integer>[] graph = new ArrayList[n];
        int[][] dist = new int[n][n];

        for(int i=0; i < n; i++)
            graph[i] = new ArrayList<>();
        
        for(int[] edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            graph[u].add(v);
            graph[v].add(u);
            dist[u][v] = edge[2];
            dist[v][u] = edge[2];
        }
        ans = values[0];        
        dfs(0, graph, dist, new int[n], maxTime, 0, values[0], values);
        return ans;
    }
    
    
    public void dfs(int current, List<Integer>[] graph, int[][] dist, int[] visited, int maxTime, int currTime, int quality, int[] values) {
        if(currTime > maxTime)
            return;
                        
        if(current == 0)
            ans = Math.max(ans, quality);
        
        visited[current]++;
        for(int node: graph[current]) {
            dfs(node, graph, dist, visited, maxTime, currTime + dist[node][current], visited[node] == 0 ? quality + values[node]: quality, values);
        }
        visited[current]--;

    }
}