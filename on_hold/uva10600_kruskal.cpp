#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

typedef pair<ll, pii> piii;
#define MAX 112

/***** START MUF *****/

int _p[MAX], _rank[MAX];

void _make(int a){ _p[a] = a; _rank[a] = 1;}

int _find(int a){ return _p[a] == a ? a : (_p[a] = _find(_p[a]) );}

void _union(int a, int b){
    if (a == b) return;
    a = _find(a); b = _find(b);
    if (_rank[a] > _rank[b])
        _p[b] = a;
    else {
        if (_rank[a] == _rank[b]) _rank[b]++;
        _p[a] = b;
    }
}

/***** END MUF *****/

vector<piii> eg;
vector<pii> mst;
ll n, m;

ll kruskal(pii curp){
    pii revp(curp.second, curp.first);
    for (ll i = 0; i < n; ++i) _make(i);

    ll ans = 0;
    for (auto &[wei, edge] : eg){
        if (edge == curp || edge == revp) continue;
        auto &[u, v] = edge;
        if (_find(u) != _find(v)){
            if(curp.first == -1) mst.PB(edge);
            ans += wei;
            _union(u, v);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; scanf("%lld", &t);
    while (t--){
        eg.clear();
        mst.clear();

        scanf("%lld %lld", &n, &m);
        for (ll i = 0; i < m; ++i){
            ll a, b, c;
            scanf("%lld %lld %lld", &a, &b, &c); a--; b--;
            eg.PB(piii(c, pii(a, b)));
        }
        sort(eg.begin(), eg.end());

        ll ans1 = kruskal(pii(-1, -1));

        ll ans2 = LL_MAX;
        for (auto &curp : mst){
            ll aaa = kruskal(curp);
            ans2 = min(ans2, aaa); 
            // printf("Interm %d %d %lld\n", curp.first, curp.second, aaa);
        }
        printf("%lld %lld\n", ans1, ans2);
    }

    return 0;
}
