#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 1123

typedef struct {
    int x, y, l;
} wall_t;

wall_t walls[MAX];
double g[MAX][MAX], dsts[MAX], pathsize[MAX];
int vis[MAX];
int n;

void change (int &a, int &b){
    int aux = a; a = b; b = aux;
}

double calc_dist(int w1, int w2){
    double dx = 0.0, dy = 0.0;
    if (walls[w1].l >= 0 && walls[w2].l >= 0){
        if (walls[w1].x >= walls[w2].x) change(w1, w2);
        dy = abs(walls[w1].y - walls[w2].y);
        dx = max(0, walls[w2].x - (walls[w1].x + walls[w1].l));
    }
    else if (walls[w1].l < 0 && walls[w2].l < 0){
        if (walls[w1].y >= walls[w2].y) change(w1, w2);
        dx = abs(walls[w1].x - walls[w2].x);
        dy = max(0, walls[w2].y - (walls[w1].y + (-walls[w1].l)));
    }
    else {
        if (walls[w1].l < 0) change(w1, w2);
        if (walls[w1].x >= walls[w2].x)
            dx = walls[w1].x - walls[w2].x;
        else
            dx = max(0, walls[w2].x - (walls[w1].x + walls[w1].l));
        if (walls[w2].y >= walls[w1].y)
            dy = walls[w2].y - walls[w1].y;
        else
            dy = max(0, walls[w1].y - (walls[w2].y + (-walls[w2].l)));
    }
    return sqrt(dx*dx + dy*dy);
}

void process(int u){
    for (int v = 0; v < n; ++v)
        if (u != v && !vis[v] && g[u][v] < dsts[v]){
            dsts[v] = g[u][v];
            pathsize[v] = max(pathsize[u], dsts[v]);
        }
    vis[u] = 1;
}

void prim(){
    memset(pathsize, 0, sizeof(pathsize));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= n; ++i)
        dsts[i] = 1e9;

    process(0);
    for (int i = 0; i < n-1; ++i){
        int cur_ind = n;
        for (int u = 0; u < n; ++u)
            if (!vis[u] && dsts[u] < dsts[cur_ind])
                cur_ind = u;
        process(cur_ind);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    scanf("%d", &n);
    while(n){
        for (int i = 0; i < n; ++i)
            scanf("%d %d %d", &(walls[i].x), &(walls[i].y), &(walls[i].l));
        
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                g[i][j] = g[j][i] = calc_dist(i, j);

        prim();
        printf("%.2f\n", pathsize[1]);
        scanf("%d", &n);
    }

    return 0;
}
