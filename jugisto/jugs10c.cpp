#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

#define ende "\n"

const int N = 1e5+15;
vector<vector<pll>> g (N);
#define NEUTRAL 0
#define OP(X, Y) ((ll)X + (ll)Y)

const int L = log2(N);
vector<int> depth (N, 0);
vector<vector<ll>> weiop (N, vector<ll>(L+1));
vector<vector<int>> up (N, vector<int>(L+1));

void bl_euler_tour(int u, int p, int w) {
    up[u][0] = p; weiop[u][0] = w; depth[u] = depth[p] + 1;
    for (auto [v, w] : g[u]) if (v != p)
    bl_euler_tour(v, u, w);
}

void bl_init(int u, int n) {
    depth[u] = 0; bl_euler_tour(u, u, 0);
    for (int l = 0; l < L; l++)
        for (int u = 0; u < n; u++) {
            int a = up[u][l];
            up[u][l+1] = up[a][l];
            weiop[u][l+1] = OP(weiop[u][l], weiop[a][l]);
        }
}

ll bl_op(int a, int b) {
    if (!(depth[a] > depth[b])) { swap(a, b); }
    ll res = NEUTRAL;
    ll diff = depth[a] - depth[b];
    for (int l = L; l >= 0; l--) if (diff & (1 << l)) 
        { res = OP(res, weiop[a][l]); a = up[a][l]; }
        if (a == b) { return res; }
        for (int l = L; l >= 0; l--)
            if (up[a][l] != up[b][l]) {
                res = OP(res, OP(weiop[a][l], weiop[b][l]));
                a = up[a][l], b = up[b][l];
            }
    return OP(res, OP(weiop[a][0], weiop[b][0]));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (ll u = 1 ; u <= n-1; ++u){
        ll v, w; cin >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    bl_init(0, n);
    int q; cin >> q;
    while (q--){
        ll u, v; cin >> u >> v;
        cout << bl_op(u, v) << ende;
    }


    return 0;
}
