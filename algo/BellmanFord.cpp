constexpr int INF = 1e9;

vector<int> bellmanFord(int n, int s, vector<vector<int>>& edge) {
    vector<int> d(n, INF);
    d[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto& e : edge) {
            int u = e[0], v = e[1], w = e[2];
            if (d[u] != INF && d[u] + w < d[v]) {
                d[v] = d[u] + w;
            }
        }
    }
    for (auto& e : edge) {
        int u = e[0], v = e[1], w = e[2];
        if (d[u] != INF && d[u] + w < d[v]) {
            d[v] = -INF; 
        }
    }
    return d;
}