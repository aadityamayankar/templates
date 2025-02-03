vector<int> toposort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> state(n), res;

    function<bool(int)> dfs = [&](int node) -> bool {
        state[node] = 1;
        for (auto& nei : adj[node]) {
            if (state[nei] == 0) {
                if (dfs(nei)) return true;
            } else if (state[nei] == 1) {
                return true;
            }
        }
        state[node] = 2;
        res.push_back(node);
        return false;
    };

    for (int i = 0; i < n; ++i) {
        if (state[i] == 0) {
            if (dfs(i)) return {};
        }
    }

    return res;
}
