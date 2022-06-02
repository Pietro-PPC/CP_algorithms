#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAXN 512

int G[MAXN][MAXN];
bool Gmin[MAXN][MAXN];
int dst[MAXN];
bool vis[MAXN];
vector<vector<int>> prnt(MAXN);

void bfs2(int S, int n){
    queue<int> Q;
    memset(vis, false, sizeof(vis));

    Q.push(S);
    vis[S] = true;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        vis[u] = true;
        for (auto v : prnt[u]){
            if (!vis[v]){
                G[u][v] = 0;
                Q.push(v);
            }
        }
    }
}

void bfs(int S, int D, int n){
    queue<int> Q;

    Q.push(S);
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for (int v = 0; v < n; ++v){
            if (Gmin[u][v]){
                // cout << "Deleta " << v << " " << u << endl;
                prnt[v].PB(u);
                Q.push(v);
            }
        }
    }
}


void dijkstra(int S, int n){
    priority_queue<pii, vector<pii>, greater<pii>> Q;

    dst[0] = 0;
    for (int i = 1; i < n; ++i)
        dst[i] = INT_MAX;
        
    memset(vis, false, sizeof(vis));

    Q.push({0, S});
    while(!Q.empty()){
        auto [d, u] = Q.top(); Q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int v = 0; v < n; ++v){
            int w = G[u][v];
            if(w && d + w < dst[v]){
                dst[v] = d + w;
                Q.push({dst[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, S, D;
    cin >> N >> M;
    while(N || M){

        cin >> S >> D;
        memset(G, 0, sizeof(G));
        for (int i = 0; i < M; ++i){
            int U, V, P;
            cin >> U >> V >> P;
            G[U][V] = P;
        }

        dijkstra(S, N);
        // for (int i = 0; i < N; ++i) cout << dst[i] << endl;
        // cout << endl;
        memset(Gmin, 0, sizeof(Gmin));
        for (int u = 0; u < N; ++u){
            for (int v = 0; v < N; ++v){
                int w = G[u][v];
                if (w && dst[u] + w == dst[v]){
                    Gmin[v][u] = w;
                    // cout << v << " " << u << " " << w << endl;
                }
            }
        }

        bfs(D, S, N);
        bfs2(S, N);

        dijkstra(S, N);
        if (dst[D] == INT_MAX)
            cout << -1 << endl;
        else 
            cout << dst[D] << endl;
        
        cin >> N >> M;
    }

    return 0;
}


// for (int i = 0; i < N; ++i){
//     for (int j = 0; j < N; ++j){
//         cout << G[i][j] << " ";
//     }
//     cout << endl;
// }