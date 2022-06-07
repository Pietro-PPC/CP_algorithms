#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 1123

int xyl[MAX][3];
double g[MAX][MAX], dsts[MAX], pathsize[MAX];
int vis[MAX];

int n;

void change (int &a, int &b){
    int aux = a; a = b; b = aux;
}

double calc_dist(int w1, int w2){
    double dx = 0.0, dy = 0.0;
    if (xyl[w1][2] >= 0 && xyl[w2][2] >= 0){
        if (xyl[w1][0] >= xyl[w2][0]) change(w1, w2);
        dy = abs(xyl[w1][1] - xyl[w2][1]);
        dx = max(0, xyl[w2][0] - (xyl[w1][0] + xyl[w1][2]));
    }
    else if (xyl[w1][2] < 0 && xyl[w2][2] < 0){
        if (xyl[w1][1] >= xyl[w2][1]) change(w1, w2);
        dx = abs(xyl[w1][0] - xyl[w2][0]);
        dy = max(0, xyl[w2][1] - (xyl[w1][1] + (-xyl[w1][2])));
    }
    else {
        if (xyl[w1][2] < 0) change(w1, w2);
        if (xyl[w1][0] >= xyl[w2][0])
            dx = xyl[w1][0] - xyl[w2][0];
        else
            dx = max(0, xyl[w2][0] - (xyl[w1][0] + xyl[w1][2]));
        if (xyl[w2][1] >= xyl[w1][1])
            dy = xyl[w2][1] - xyl[w1][1];
        else
            dy = max(0, xyl[w1][1] - (xyl[w2][1] + (-xyl[w2][2])));
    }
    return sqrt(dx*dx + dy*dy);
}

void process(int u){
    for (int v = 0; v < n; ++v){
        if (u != v && !vis[v] && g[u][v] < dsts[v]){
            dsts[v] = g[u][v];
            pathsize[v] = max(pathsize[u], dsts[v]);
        }
    }
    vis[u] = 1;
}

void prim(){
    memset(pathsize, 0, sizeof(pathsize));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i)
        dsts[i] = 1e9;

    process(0);
    for (int i = 0; i < n-1; ++i){
        double mindst = 1e9, cur_ind = -1;
        for (int u = 0; u < n; ++u)
            if (!vis[u] && dsts[u] < mindst)
                {mindst = dsts[u]; cur_ind = u;}
        process(cur_ind);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    scanf("%d", &n);
    while(n){
        for (int i = 0; i < n; ++i)
            scanf("%d %d %d", &(xyl[i][0]), &(xyl[i][1]), &(xyl[i][2]));
        
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                g[i][j] = g[j][i] = calc_dist(i, j);

        prim();
        printf("%.2f\n", pathsize[1]);
        scanf("%d", &n);
    }

    return 0;
}
