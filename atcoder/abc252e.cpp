#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 212345

ll n, m;
vector<vector<pll>> G(MAX);
vector<vector<int>> child(MAX);
ll prnt[MAX], dst[MAX];
bool vis[MAX];
map<pll, int> ind_edge;

void dijkstra(int st){
    priority_queue<pll, vector<pll>, greater<pll>> Q;
    for (int i = 0; i< MAX; ++i){
        dst[i] = LL_MAX;
    }
    dst[st] = 0;
    memset(prnt, -1, sizeof(prnt));
    memset(vis, false, sizeof(vis));

    Q.push({0, st});
    while(!Q.empty()){
        auto [d, u] = Q.top(); Q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, w] : G[u]){
            if (dst[v] > dst[u] + w){
                dst[v] = dst[u] + w;
                prnt[v] = u;
                Q.push({dst[v], v});
            }
        }
        if (prnt[u] != -1)
            child[prnt[u]].PB(u);
    }
}

void dfs(int st){
    if (vis[st]) return;
    vis[st] = true;
    for (auto u : child[st]){
        if (ind_edge[{st,u}])
            cout << ind_edge[{st, u}] << " ";
        else
            cout << ind_edge[{u, st}] << " ";
        dfs(u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        ind_edge[{a, b}] = i+1;
        G[a].PB({b, c});
        G[b].PB({a, c});
    }

    dijkstra(1);
    memset(vis, false, sizeof(vis));
    dfs(1);
    cout << endl;

    return 0;
}
