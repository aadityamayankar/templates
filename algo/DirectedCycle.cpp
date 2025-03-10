bool cycle(vector<vector<int>> adj) {
    int n = adj.size();
    vector<int> state(n);

    function<bool(int)> dfs = [&](int u) {
        state[u] = 1;
        for (int v : adj[u]) {
            if (state[v] == 1) return true;
            if (state[v] == 0 && dfs(v)) return true;
        }
        state[u] = 2;
        return false;
    };

    for (int i = 0; i < n; i++) {
        if (state[i] == 0 && dfs(i)) return true;
    }
    return false;
}