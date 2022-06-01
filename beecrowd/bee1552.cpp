#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define INF 112345.0
#define MAX 512

typedef pair<double, int> pdi;

int coords[MAX][2];
double g[MAX][MAX];
int n;

double calc_dist(int i, int j){
    int dx = abs(coords[i][0] - coords[j][0]);
    int dy = abs(coords[i][1] - coords[j][1]);
    return sqrt(dx*dx + dy*dy);
}

double prim(){
    priority_queue<pdi, vector<pdi>, greater<pdi>> q;
    bool vis[MAX];
    double dst[MAX], ans=0.0;    

    memset(vis, 0, sizeof(vis));
    q.push(pdi(dst[0] = 0.0, 0));
    for (int u = 1; u < n; ++u){
        q.push(pdi(dst[u] = INF, u));
    }
    while (!q.empty()){
        auto [w, u] = q.top(); q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        // printf("%.3f\n", w);
        ans += w;
        for (int v = 0; v < n; ++v){
            if (u == v || vis[v]) continue;
            if (g[u][v] < dst[v])
                q.push(pdi(dst[v] = g[u][v], v));
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; scanf("%d", &t);
    while (t--){
        memset(g, 0, sizeof(g));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &coords[i][0], &coords[i][1]);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                g[i][j] = calc_dist(i,j);
                // printf("%.2f ", g[i][j]);
            }
            // printf("\n");
        }
        printf("%.2f\n", prim()/100);
    }

    return 0;
}
