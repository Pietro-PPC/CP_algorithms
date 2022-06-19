#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 512

int n, m;
vector<vector<pii>> g(MAX);
int gmin[MAX][MAX], dst[MAX];

void dijkstra(int s){
    int vis[MAX];

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) dst[i] = INT_MAX;
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    pq.push({0, s});
    dst[s] = 0;
    while (!pq.empty()){
        auto [d, um] = pq.top(); pq.pop();
        if (vis[um]) continue;
        vis[um] = 1;
        for (auto &[v, w] : g[um]){
            if (dst[um]+w < dst[v] && !gmin[um][v]){
                dst[v] = dst[um]+w;
                pq.push({dst[v], v});
            }
        }
    }
}

bool dfs(int s, int d, int vis[MAX]){
    if (s == d) return true;
    vis[s] = 1;
    bool ret = false;
    for (int v = 0; v < n; ++v){
        if (gmin[s][v] && !vis[v]){
            int res = dfs(v, d, vis);
            if (!res) gmin[s][v] = 0;
            ret = ret || res;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while (n || m){
        for (int i = 0; i < n; ++i) g[i].clear();
        memset(gmin, 0, sizeof(gmin));
        int s, d; cin >> s >> d;
        for (int i = 0; i < m; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].PB({v, w});
        }
        dijkstra(s);
        for (int u = 0; u < n; ++u)
            for (auto &[v, w] : g[u])
                if (dst[v] == dst[u]+w)
                    gmin[u][v] = 1;
        
        int vis[MAX];
        memset(vis, 0, sizeof(vis));
        dfs(s, d, vis);
        dijkstra(s);
        cout << (dst[d] == INT_MAX ? -1 : dst[d]) << ende;

        cin >> n >> m;
    }

    return 0;
}
