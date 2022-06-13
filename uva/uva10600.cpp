#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112

int g[MAX][MAX];
int vis[MAX], prnt[MAX], dst[MAX];
int n, m;
vector<pii> eg;

void process(int u){
    vis[u] = 1;
    for (int v = 0; v < n; ++v)
        if (!vis[v] && g[u][v] < dst[v]){
            prnt[v] = u;
            dst[v] = g[u][v];
        }
}

int prim(int build){
    int ans = 0;
    memset(vis, 0, sizeof(vis));
    for (int u = 0; u <= n; ++u){
        prnt[u] = n;
        dst[u] = INT_MAX;
    } 

    process(0);
    for (int i = 0; i < n-1; ++i){
        int cur = n;
        for (int u = 0; u < n; ++u)
            if (!vis[u] && dst[u] < dst[cur])
                cur = u;

        if (build) eg.push_back(pii(cur, prnt[cur]));
        else if (dst[cur] == INT_MAX) return INT_MAX;
        ans += dst[cur];
        process(cur);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &m);

        eg.clear();
        for (int u = 0; u <= n; ++u)
            for (int v = 0; v <= n; ++v)
                g[u][v] = INT_MAX;

        for (int i = 0; i < m; ++i){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c); a--; b--;
            g[a][b] = g[b][a] = c;
        }

        int ans1 = prim(1);
        int ans2 = INT_MAX;
        for (auto &[u, v] : eg){
            int aux = g[u][v];
            g[u][v] = g[v][u] = INT_MAX;
            int pr = prim(0);
            ans2 = min(ans2, pr);
            g[u][v] = g[v][u] = aux;
        }
        printf("%d %d\n", ans1, ans2);
    }

    return 0;
}