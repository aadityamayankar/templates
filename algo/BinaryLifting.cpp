class AncestorQuerier {
    public:
    int n,m,limit;
    vector<int> parent;
    vector<vector<int>> up;
    AncestorQuerier(Tree* root) {
        n = mx(root), limit = 20, m = mn(root);
        parent = vector<int>(n+1,-1), up = vector<vector<int>>(n+1,vector<int>(20,-1));
        dfs(root,-1);
        binary_lifting();
    }

    int mx(Tree* root){
        if(!root) return 0;
        return max({root->val,mx(root->left),mx(root->right)});
    }

    int mn(Tree* root){
        if(!root) return INT_MAX;
        return min({root->val,mn(root->left),mn(root->right)});
    }

    void binary_lifting(){
        for(int i=0;i<limit;i++){
            for(int j=m;j<=n;j++){
                if(i == 0) up[j][i] = parent[j];
                else{
                    int x = up[j][i-1];
                    if(x >= 0) up[j][i] = up[x][i-1];
                }
            }
        }
    }

    void dfs(Tree* root,int par){
        if(!root) return;
        dfs(root->left,root->val), dfs(root->right,root->val);
        parent[root->val] = par;
    }

    int getAncestor(int val, int k) {
        if(k == 0 || val == -1) return val;
        int log = log2(k), mx_pow = 1 << log;
        return getAncestor(up[val][log],k - mx_pow);
    }
};