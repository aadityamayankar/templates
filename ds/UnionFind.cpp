class UnionFind{
	int connected;
    vector<int> parent, sz;
    public:
    UnionFind(int n){
        parent.resize(n + 1), sz.resize(n + 1, 1), connected = n, iota(parent.begin(),parent.end(),0);
    }
    int find(int n){
        while(n != parent[n]) parent[n] = parent[parent[n]], n = parent[n];
		return n;
    }
    int size(int n){
		return sz[find(n)];
    }
    int unify(int u,int v){
        u = find(u), v = find(v);
        if(u == v) return 0;
		connected--;
        if(sz[u] > sz[v]) swap(u,v);
		sz[v] += sz[u], sz[u] = 0, parent[u] = parent[v];
        return 1;
    }
};
