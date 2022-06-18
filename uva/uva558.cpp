// tags: bellman-ford

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 1123

int n, m, lg[MAX][MAX], d[MAX], ag[MAX][MAX];

bool bford(){
    int dst[MAX];
    memset(dst, INT_MAX, sizeof(dst));
    dst[0] = 0;
    for (int i = 0; i < n-1; ++i)
        for (int u = 0; u < n; ++u)
            if (dst[u] != INT_MAX)
                for (int j = 0; j < d[u]; ++j){
                    int v = lg[u][j];
                    dst[v] = min(dst[v], dst[u]+ag[u][v]);
                }

    bool ret = false;
    for (int u = 0; u < n; ++u){
        if (dst[u] != INT_MAX)
            for (int j = 0; j < d[u]; ++j){
                int v = lg[u][j];
                if (dst[u]+ag[u][v] < dst[v]) ret = true;
            }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        int u, v, w;
        memset(d, 0, sizeof(d));
        for (int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            lg[u][d[u]++] = v;
            ag[u][v] = w;
        }
        cout << (bford() ? "possible" : "not possible") << ende;
    }

    return 0;
}
