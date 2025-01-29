class Tarjans{
    vector<vector<int>> adj;
    vector<int> low, disc, scc;
    stack<int> st;
    int time, scc_count;
    public:
    Tarjans(int n){
        adj.resize(n + 1), low.resize(n + 1), disc.resize(n + 1, -1), scc.resize(n + 1, -1), time = 0, scc_count = 0;
    }
    Tarjans(vector<vector<int>> &adj):adj(adj){
        low.resize(adj.size()), disc.resize(adj.size(), -1), scc.resize(adj.size(), -1), time = 0, scc_count = 0;
    }
    void add_edge(int u,int v){
        adj[u].push_back(v);
    }
    void dfs(int u){
        low[u] = disc[u] = time++;
        st.push(u);
        for(auto &v:adj[u]){
            if(disc[v] == -1){
                dfs(v);
                low[u] = min(low[u], low[v]);
            }else if(scc[v] == -1){
                low[u] = min(low[u], disc[v]);
            }
        }
        if(low[u] == disc[u]){
            while(st.top() != u){
                scc[st.top()] = scc_count;
                st.pop();
            }
            scc[st.top()] = scc_count++;
            st.pop();
        }
    }
    vector<vector<int>> get_scc(){
        for(int i = 1; i < adj.size(); i++){
            if(disc[i] == -1){
                dfs(i);
            }
        }
        vector<vector<int>> res(scc_count);
        for(int i = 1; i < adj.size(); i++){
            res[scc[i]].push_back(i);
        }
        return res;
    }
};