#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 2123

int g[MAX][MAX];
int n, m;

int prim(){
    int ans = 0, ok[MAX];
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    memset(ok, 0, sizeof(ok));
    ok[0] = 1;

    for (int i = 0; i < n; ++i)
        if (g[0][i])
            pq.push(pii(g[0][i], i));

    while(!pq.empty()){
        auto [w, u] = pq.top(); pq.pop();
        if (ok[u]) continue;
        ok[u] = 1;
        ans += w;
        for (int v = 0; v < n; ++v){
            if (g[u][v]){
                pq.push( pii(g[u][v], v) );
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<string, int> s2u;

    int t; scanf("%d", &t);
    while (t--){
        int wei, cnt = 0;
        char b[10], e[10];
        memset(g, 0, sizeof(g));
        s2u.clear();

        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i){
            scanf("%s %s %d", b, e, &wei);
            string str1(b), str2(e);
            if (s2u.find(str1) == s2u.end()){
                s2u[str1] = cnt++;
            }
            if (s2u.find(str2) == s2u.end()){
                s2u[str2] = cnt++;
            }
            g[ s2u[str1] ][ s2u[str2] ] = wei;
            g[ s2u[str2] ][ s2u[str1] ] = wei;
        }
        printf("%d\n%s", prim(), t ? "\n" : "");
    }

    return 0;
}
