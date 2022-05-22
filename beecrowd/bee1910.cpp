#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112345
#define MAX_CHAN 100000
vector<vector<int>> G(MAX);
int vis[MAX], dst[MAX];

void build(){
    for (int ch = 1; ch <= MAX_CHAN; ++ch){
        if (ch%2 == 0)
            G[ch].PB(ch/2);
        if (ch>1)
            G[ch].PB(ch-1);
        if (ch<MAX)
            G[ch].PB(ch+1);
        if (ch*3 <= MAX)
            G[ch].PB(ch*3);
        if (ch*2 <= MAX)
            G[ch].PB(ch*2);
    }
}

int bfs(int o, int d){
    queue<int> q;
    memset(dst, -1, sizeof(dst));

    dst[o] = 0;
    q.push(o);
    while(!q.empty()){
        int ch = q.front(); q.pop();
        for (int nex : G[ch]){
            if (!vis[nex]){
                dst[nex] = dst[ch]+1;
                vis[nex] = true;
                q.push(nex);
            }
        }
    }

    return dst[d];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int o, d, k;
    build();
    cin >> o >> d >> k;
    while (o || d || k){
        int cur;
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < k; ++i){
            cin >> cur;
            vis[cur] = true;
        }
        
        cout << bfs(o, d) << endl;

        cin >> o >> d >> k;
    }    

    return 0;
}
