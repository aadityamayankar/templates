constexpr int INF = 1e9;

vector<int> dijkstra(int s, vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();
    vector<int> d(n, INF);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int u = q.begin()->second; q.erase(q.begin());
        for (auto& edge : adj[v]) {
            int v = edge.first, w = edge.second;
            if (d[u] + w < d[v]) {
                q.erase({d[v], v});
                d[v] = d[u] + w;
                q.insert({d[v], v});
            }
        }
    }
    return d;
}