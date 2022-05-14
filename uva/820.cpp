#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define MAXN 112

int n;

int bfs(int G[MAXN][MAXN], int pai[MAXN], int s, int t){
    queue<int> q;
    int v[MAXN];
    q.push(s);

    for (int i = 0; i < n; ++i) pai[i] = -1;
    memset(v, 0, MAXN*sizeof(int));
    while ( !(q.empty()) ){
        int cur = q.front();
        q.pop();
        for (int i = 0; i < n; ++i){ // arestas que saem de G
            if (G[cur][i] && !v[i]){
                v[i] = 1;
                pai[i] = cur;
                q.push(i);
            }
        }
    }

    int mi = INT_MAX;
    int it;
    for (it = t; it != s && pai[it] != -1; it = pai[it]){
        // cout << pai[it] << " " << it << " " <<  G[pai[it]][it] << endl;
        mi = min(mi, G[pai[it]][it]);
    }
    if (it == t) mi = 0;
    return mi;
}

int ffk(int G[MAXN][MAXN], int s, int t){
    int ret = 0, ans;
    int pai[MAXN];
    for (int i = 0; i < n; ++i) pai[i] = -1;
    while (ans = bfs(G, pai, s, t)){
        ret += ans;
        for (int it = t; it != s; it = pai[it]){
            G[pai[it]][it] -= ans;
            G[it][pai[it]] += ans;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int G[MAXN][MAXN];

    int cnt = 1;
    while (n){
        memset(G, 0, MAXN*MAXN*sizeof(int));
        int s, t, c;
        cin >> s >> t >> c; s--; t--;
        for (int i = 0; i < c; ++i){
            int na, nb, w;
            cin >> na >> nb >> w; na--; nb--;
            G[na][nb] += w;
            G[nb][na] += w;
        }

        int ans = ffk(G, s, t);
        cout << "Network " << cnt << endl;
        cout << "The bandwidth is " << ans << '.' << endl << endl;

        cnt++;
        cin >> n;
    }

    return 0;
}
