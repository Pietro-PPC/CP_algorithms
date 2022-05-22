#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112345
#define MAXN 100000
#define OFF 10

vector<vector<int>> G(MAX);
int vis[MAX], dst[MAX];

void build(){
    for (int i = -OFF; i <= MAXN; ++i){
        if (2*i <= MAXN && 2*i >= -OFF)
            G[i+OFF].PB(2*i);
        if (3*i <= MAXN && 3*i >= -OFF)
            G[i+OFF].PB(3*i);
        if (7+i <= MAXN)
            G[i+OFF].PB(7+i);
        if (i-7 >= -OFF)
            G[i+OFF].PB(i-7);
        G[i+OFF].PB(i/2);
        G[i+OFF].PB(i/3);
    }
}

int bfs(int n, int m){
    queue<int> q;

    memset(vis, 0, sizeof(vis));
    memset(dst, -1, sizeof(dst));

    dst[n+OFF] = 0;
    vis[n+OFF] = true;
    q.push(n);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(vis[m+OFF]) continue;
        for (int next : G[cur+OFF]){
            if (!vis[next+OFF]){
                dst[next+OFF] = dst[cur+OFF]+1;
                vis[next+OFF] = true;
                q.push(next);
            }
        }
    }
    return dst[m+OFF];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    build();
    cout << bfs(n, m) << endl;

    return 0;
}
