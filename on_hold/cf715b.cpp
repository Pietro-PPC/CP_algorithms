#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 1123
ll g[MAX][MAX], prnt[MAX];
ll dst[MAX];
ll l_eg1, l_eg2;
ll n;

void dijkstra(ll s, int ign){
    ll vis[MAX];
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;

    for (ll i = 0; i < n; ++i) dst[i] = LL_MAX;
    dst[s] = 0;
    pq.push({dst[s], {s, s}});
    while (!pq.empty()){
        auto [d, eg] = pq.top(); pq.pop();
        auto [u, paru] = eg;
        if (vis[u]) continue;
        vis[u] = 1;
        prnt[u] = paru;
        for (ll v = 0; v < n; ++v){
            if (!vis[v] && g[u][v] < LL_MAX){
                ll isnull = !g[u][v];
                if (isnull && ign) continue;
                if (isnull && !ign) g[u][v] = 1;
                if (dst[u]+(ll)g[u][v] < dst[v]){
                    dst[v] = dst[u]+(ll)g[u][v];
                    pq.push({dst[v], {v, u}});
                }
                if (isnull && !ign) g[u][v] = 0;
            }
        }
    }
}

void dfs(ll s, ll t){
    ll vis[MAX];
    memset(vis, 0, sizeof(vis));
    stack<ll> st;
    st.push(s);
    while (!st.empty()){
        ll u = st.top(); st.pop();
        vis[u] = 1;
        for (ll v = 0; v < n; ++v){
            if (g[u][v] < LL_MAX && !vis[v]) {
                if (g[u][v] == 0){
                    l_eg1 = v; l_eg2 = u;
                    while (!st.empty()) st.pop();
                    break;
                }
                else st.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < n; ++j)
            g[i][j] = LL_MAX;

    for (ll i = 0; i < m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    dijkstra(s, 1);
    if (dst[t] < l){
        cout << "NO" << ende;
        return 0;
    }
    dijkstra(s, 0);
    // for (ll i = 0; i < n; ++i){
    //     cout << dst[i] << " ";
    // } cout << ende;
    dfs(s, t);
    if (dst[t] > l)
        cout << "NO" << ende;
    else{
        cout << "YES" << ende;
        g[l_eg1][l_eg2] = g[l_eg2][l_eg1] = 1 + l-dst[t];
        for (ll u = 0; u < n; ++u){
            for (ll v = u+1; v < n; ++v){
                if (g[u][v] != LL_MAX)
                    cout << u << " " << v << " " << (!g[u][v] ? 1 : g[u][v]) << ende;
            }
        }
    }

    return 0;
}
