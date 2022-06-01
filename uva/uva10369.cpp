#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

typedef pair<double, int> pdi;
#define MAX 512
#define INF 1e9

double coord[MAX][2];
double g[MAX][MAX];
double dst[MAX];
int s, p;

double calc_dist(int i, int j){
    double dx = abs(coord[i][0] - coord[j][0]);
    double dy = abs(coord[i][1] - coord[j][1]);
    return sqrt(dx*dx + dy*dy);
}

void prim(){
    int vis[MAX];
    memset(vis, 0, sizeof(vis));

    dst[0] = 0.0;
    for (int u = 1; u < p; ++u)
        dst[u] = INF;

    for (int i = 0; i < p-1; ++i){
        int cur = -1;
        for (int u = 0; u < p; ++u)
            if (!vis[u] && (cur == -1 || dst[u] < dst[cur]))
                cur = u;

        for (int u = 0; u < p; ++u){
            if (u != cur && !vis[u]) 
                dst[u] = min(dst[u], g[cur][u]);
        }
        vis[cur] = 1;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; scanf("%d", &t);
    while (t--){
        scanf("%d %d", &s, &p);
        memset(coord, 0, sizeof(coord));
        memset(dst, 0, sizeof(dst));
        memset(g, 0, sizeof(g));
        
        for (int i = 0; i < p; ++i)
            scanf("%lf %lf", &coord[i][0], &coord[i][1]);
        
        for (int i = 0; i < p; ++i){
            for (int j = 0; j < p; ++j)
                g[i][j] = calc_dist(i, j);
        }
        prim();
        sort(dst, dst+p);
        printf("%.2f\n", dst[p-s]);
    }

    return 0;
}
