vector<int> toposort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> res, vis(n);

    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
        res.push_back(u);
    };

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    return vector<int>(res.rbegin(), res.rend());
}