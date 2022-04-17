#include <bits/stdc++.h>
using namespace std;
//lc
using ll =          long long;
using ull =         unsigned long long;
using ld =          long double;
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define sz(x)       (int)(x).size()
#define len(x)      (int)(x).length()
#define each(i,x)   for (auto& i: x)
#define maxi(x)     *max_element(all(x))
#define mini(x)     *min_element(all(x))
#define sum(x)      accumulate(all(x),0)
typedef             pair<int,int> pi;
constexpr int mod =     1e9 + 7;

class Solution {
public:
	int divide(int dividend, int divisor) {
        ll res = 1ll * dividend / divisor;
        if(res > INT_MAX) return INT_MAX;
        else if(res < INT_MIN) return INT_MIN;
        return res;
    }
};

#ifdef ONLINE_JUDGE
int main(){cout << "Compiled!";}
#endif