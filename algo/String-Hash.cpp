long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}



constexpr int N = 1e5 + 7;
constexpr int p = 31;
constexpr int m = 1e9 + 9;
int p_pow[N];
int h[N];

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void pre() {
    p_pow[0] = 1;
    for (int i = 1; i < N; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }
}

void compute_hash(string const& s) {
    h[0] = 0;
    for (int i = 0; i < s.size(); i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
}

// Returns the hash of the substring s[l..r]
int get_hash(int l, int r) {
    return ((h[r + 1] - h[l]) * binpow(p_pow[l], m - 2) % m + m) % m;
}