constexpr int INF = 1e9;

vector<int> bfs01(int s, vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();
    vector<int> d(n, INF);
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto& edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (w == 0) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
    return d;
}