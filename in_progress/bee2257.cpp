#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAX_LL 0x7fffffffffffffff

#define MAXN 25123
#define MAXC 1123

int start[MAXC], prnt[MAXN];
ll dst[MAXN];

void dijkstra(vector<vector<pii>> g, int s){
    priority_queue<pair<ll, int>, 
        vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    
    bool vis[MAXN];
    for (int i = 0; i < g.size(); ++i){
        dst[i] = MAX_LL;
        vis[i] = false;
        prnt[i] = -1;
    }
    dst[0] = 0;

    Q.push({dst[0], 0});
    while (!Q.empty()){
        pair<ll, int> cur = Q.top(); Q.pop();
        if (vis[cur.second]) continue;
        vis[cur.second] = true;
        for (auto it : g[cur.second]) {
            if (dst[it.first] > dst[cur.second] + it.second){
                dst[it.first] = dst[cur.second] + it.second;
                prnt[it.first] = cur.second;
                Q.push({dst[it.first], it.first});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<pii>> g(n);

    for (int i = 0; i < m; ++i){
        int xi, yi, ti;
        cin >> xi >> yi >> ti; xi--; yi--;
        g[xi].push_back({yi, ti});
        g[yi].push_back({xi, ti});
    }
    for(int i = 0; i < c; ++i){
        cin >> start[i];
    }

    dijkstra(g, 0);
    for (int i = 0; i < n; ++i){
        cout << i << " " << prnt[i] << " " << dst[i] <<  endl;
    }

    return 0;
}
