#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

typedef pair<int, pii> piii;
#define MAX 100

int c, s, q;
vector<pii> g[MAX], mst[MAX];
int maxsound[MAX][MAX];

void bfs(int src){
    int vis[MAX];
    queue<int> q;
    memset(vis, 0, sizeof(vis));

    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &[v, w] : mst[u]){
            if (!vis[v]){
                vis[v] = 1;
                maxsound[src][v] = maxsound[v][src] = max(maxsound[src][u],w); 
                q.push(v);
            }
        }
    }
}

void prim(){
    priority_queue<piii, vector<piii>, greater<piii>> q;
    int vis[MAX];
    memset(vis, 0, sizeof(vis));

    // graph may have more than one component
    for (int vert = 0; vert < c; ++vert){
        if (vis[vert]) continue;
        for (auto &[v, wei] : g[vert])
            q.push(piii(wei, pii(vert,v)));
        
        vis[vert] = 1;
        int u, v;
        while(!q.empty()){
            auto [wei, edge] = q.top(); q.pop();
            tie(u,v) = edge;
            if (vis[v]) continue;
            vis[v] = 1;
            mst[u].PB(pii(v, wei));
            mst[v].PB(pii(u, wei));
            for (auto &[z, w] : g[v]){
                if (!vis[z])
                    q.push(piii(w, pii(v, z)));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int curcase = 1;
    scanf("%d %d %d", &c, &s, &q);
    while (c || s || q){
        memset(maxsound, 0, sizeof(maxsound));
        for (int i = 0; i < c; ++i) {
            g[i].clear();
            mst[i].clear();
        }

        for (int i = 0; i < s; ++i) {
            int c1, c2, wei;
            scanf("%d %d %d", &c1, &c2, &wei); c1--; c2--;
            g[c1].PB(pii(c2, wei));
            g[c2].PB(pii(c1, wei));
        }

        prim(); // Builds mst graph
        for (int u = 0; u < c; ++u)
            bfs(u); // fills maxsound, maximum sound intensity between vertices

        printf("Case #%d\n", curcase);
        for (int i = 0; i < q; ++i){
            int c1, c2;
            scanf("%d %d", &c1, &c2); c1--, c2--;
            if (maxsound[c1][c2]) 
                printf("%d\n", maxsound[c1][c2]);
            else 
                printf("no path\n");
        }
        curcase++;
        scanf("%d %d %d", &c, &s, &q);
        if (c || s || q)
            printf("\n");
    }

    return 0;
}
