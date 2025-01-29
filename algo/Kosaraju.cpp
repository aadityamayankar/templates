void scc(vector<vector<int>> adj) {
    int n = adj.size();
    vector<vector<int>> adj_rev(n);
    for(int i = 0; i < n; i++){
        for(auto &j:adj[i]){
            adj_rev[j].push_back(i);
        }
    }
    vector<int> order, component(n, -1);
    vector<bool> vis(n, false);

    function<void(int)> dfs1 = [&](int u) -> void {
        vis[u] = true;
        for(auto &v : adj[u]){
            if (!vis[v]) dfs1(v);
        }
        order.push_back(u);
    };

    function<void(int, int)> dfs2 = [&](int u, int comp) -> void {
        component[u] = comp;
        for(auto &v : adj_rev[u]){
            if(component[v] == -1){
                dfs2(v, comp);
            }
        }
    };

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }

    int comp = 0;
    for(int i = n - 1; i >= 0; i--){
        if(component[order[i]] == -1){
            dfs2(order[i], comp++);
        }
    }

    vector<vector<int>> res(comp);
    for(int i = 0; i < n; i++){
        res[component[i]].push_back(i);
    }

    for(auto &i:res){
        for(auto &j:i){
            cout << j << " ";
        }
        cout << endl;
    }
}