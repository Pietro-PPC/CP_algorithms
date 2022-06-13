#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 11234

int pr[MAX];
vector<vector<pii>> g(MAX);

int dijkstra(int c, int s, int e){
    int vis[MAX][112];
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;

    memset(vis, 0, sizeof(vis));

    pq.push({0, {s, 0}});
    while(!pq.empty()){
        auto [mo, st] = pq.top(); pq.pop();
        auto &[ci, ta] = st;
        if (vis[ci][ta]) continue;
        vis[ci][ta] = 1;
        if (ci == e) return mo;
        if (ta < c) pq.push({mo+pr[ci], {ci, ta+1}});
        for (auto &[v, w] : g[ci]){
            if (ta-w < 0) continue;
            if (!vis[v][ta-w])
                pq.push({mo, {v, ta-w}});
        }
    }
    return INT_MAX;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> pr[i];
    for (int i = 0; i < m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        g[a].PB(MP(b, w));
        g[b].PB(MP(a, w));
    }

    int q;
    cin >> q;
    while (q--){
        int c, s, e; cin >> c >> s >> e;
        int ans = dijkstra(c, s, e);
        if (ans == INT_MAX) cout << "impossible\n";
        else cout << ans << ende;
    }

    return 0;
}
