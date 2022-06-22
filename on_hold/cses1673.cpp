#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 2512

vector<vector<pii>> g(MAX);
int n, m;

ll bellford(int s, int t){
    ll dst[MAX];
    for (int u = 0; u < n; ++u) dst[u] = LL_MAX;

    dst[s] = 0;
    for (int i = 0; i < n-1; ++i)
        for (int u = 0; u < n; ++u)
            if (dst[u] < LL_MAX)
                for (auto &[v, w] : g[u])
                    dst[v] = min(dst[v], dst[u]+w);

    ll ans = -1*dst[t];
    for (int u = 0; u < n; ++u)
        if (dst[u] < LL_MAX)
            for (auto &[v, w] : g[u])
                if (dst[u]+w < dst[v]) ans = -1;

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u, v; ll w;
        cin >> u >> v >> w; --u, --v;
        g[u].push_back({v, -w});
    }

    cout << bellford(0, n-1) << ende;
    return 0;
}
