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
int n, m;
vector<pii> eg;

int prim(int build){
    int prnt[MAX], vis[MAX];
    int ans = 0;

    memset(prnt, -1, sizeof(prnt));
    memset(vis, 0, sizeof(vis));
    for (int u = 1; u < n; ++u){
        if(g[0][u]) prnt[u] = 0;
    }
    vis[0] = 1;
    for (int i = 0; i < n-1; ++i){
        int cur = -1;
        for (int u = 0; u < n; ++u){
            if (vis[u] || prnt[u] == -1) continue;
            if (cur == -1 || g[u][prnt[u]] < g[cur][prnt[cur]])
                cur = u;
        }
        vis[cur] = 1;

        if (build) eg.push_back(pii(cur, prnt[cur]));
        ans += g[cur][prnt[cur]];
        for(int u = 0; u < n; ++u){
            if (!vis[u] && g[u][cur] && (prnt[u] == -1 || g[u][cur] < g[u][prnt[u]]))
                prnt[u] = cur;
        }
        // if (prnt[cur] > -1) printf("cur %d %d\n", cur, g[cur][prnt[cur]]);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &m);
        memset(g, 0, sizeof(g));

        for (int i = 0; i < m; ++i){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            a--; b--;
            g[a][b] = c;
            g[b][a] = c;
        }

        int ans1 = prim(1);
        int ans2 = INT_MAX;
        for (auto &[u, v] : eg){
            int aux = g[u][v];
            g[u][v] = 0;
            g[v][u] = 0;
            int pr = prim(0);
            ans2 = min(ans2, pr);
            g[u][v] = aux;
            g[v][u] = aux;
            // printf("%d %d %d\n\n", u, v, pr);
        }
        // printf("\n");
        eg.clear();
        printf("%d %d\n", ans1, ans2);
    }

    return 0;
}