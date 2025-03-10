constexpr int INF = 2e9;
constexpr int N = 1e5 + 5;
int st[N << 2 | 1];

void build(int v, int l, int r, int arr[]) {
    if (l == r) st[v] = arr[l];
    else {
        int m = l + ((r - l) >> 1);
        build(v << 1, l, m, arr);
        build(v << 1 | 1, m + 1, r, arr);
        st[v] = min(st[v << 1], st[v << 1 | 1]);
    }
}

int qry(int v, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return INF;
    if (l >= ql && r <= qr) return st[v];
    int m = l + ((r - l) >> 1);
    return min(qry(v << 1, l, m, ql, qr), qry(v << 1 | 1, m + 1, r, ql, qr));
}

void upd(int v, int l, int r, int idx, int val) {
    if (l == r) st[v] = val;
    else {
        int m = l + ((r - l) >> 1);
        if (idx <= m) upd(v << 1, l, m, idx, val);
        else upd(v << 1 | 1, m + 1, r, idx, val);
        st[v] = min(st[v << 1], st[v << 1 | 1]);
    }
}