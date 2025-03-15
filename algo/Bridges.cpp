vector<vector<int>> getBridges(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, false);
    vector<int> in_time(n, 0), low_time(n, n);
    vector<vector<int>> bridges;
    int time = 0;

    function<void(int, int)> dfs = [&](int node, int par) -> void {
        vis[node] = true;
        in_time[node] = low_time[node] = time++;
        for (auto& nei : adj[node]) {
            if (nei == par) continue;
            if (vis[nei]) {
                low_time[node] = min(low_time[node], low_time[nei]);
            } else {
                dfs(nei, node);
                low_time[node] = min(low_time[node], low_time[nei]);
                if (in_time[node] < low_time[nei]) bridges.push_back({node, nei});
            }
        }
    };

    dfs(0, -1);
    return bridges;
}