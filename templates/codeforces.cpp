#include <bits/stdc++.h>
using namespace std;
//cf
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll inf = 4e18;
constexpr ld eps = 1e-9;
// constexpr ll mod = 998244353;
constexpr ll mod = 1e9 + 7;

#define int         long long
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define sz(x)       (int)(x).size()
#define len(x)      (int)(x).length()
#define each(i,x)   for (auto& i: x)
#define maxi(x)     *max_element(all(x))
#define mini(x)     *min_element(all(x))
#define sum(x)      accumulate(all(x),0)

using pi = pair<int, int>;

struct custom_hash{
	static uint64_t splitmix64(uint64_t x){
		x += 0x9e3779b97f4a7c15, x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9, x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p){return (istream >> p.first >> p.second);}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p){return (ostream << p.first << " " << p.second);}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c){for (auto &it : c)cout << it << " ";return ostream;}
template <typename T>
void print(T &&t) { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&...args){cout << t << " ";print(forward<Args>(args)...);}

//....................................................................................................................

constexpr bool areTests = 1;

void solve(){

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);
    // cout << setprecision(12) << fixed;
    int t = 1;
    if(areTests) cin>>t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}