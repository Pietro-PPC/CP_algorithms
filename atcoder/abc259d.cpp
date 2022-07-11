#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7f7f7f7f7f7f7f7f
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 3123
#define EPS 0.000001

struct circle{
    ll x, y, r;
};

ll gc[MAX][MAX];
ll n; 

ll dist(ll ax, ll ay, ll bx, ll by){
    ll dx, dy;
    dx = ax-bx;
    dy = ay-by;
    return dx*dx + dy*dy;
}

ll incirc(ll a, ll b, circle &ci){
    return dist(a, b, ci.x, ci.y) ==  ci.r*ci.r;
}

ll intersect(circle &a, circle &b){
    ll dc = dist(a.x, a.y, b.x, b.y);
    if (dc > (a.r+b.r)*(a.r+b.r) || dc < (a.r-b.r)*(a.r-b.r)) return 0;
    return 1;
}

ll dfs(ll s, ll t){
    stack<ll> st;
    ll vis[MAX];
    
    memset(vis, 0, sizeof(vis));
    vis[s] = 1;
    st.push(s);
    while (!st.empty()){
        ll u = st.top(); st.pop();
        for (ll v = 0; v < n; ++v){
            if (u != v && !vis[v] && gc[u][v]){
                st.push(v);
                vis[v] = 1;
            }
        }
    }
    return vis[t];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll sx, sy, tx, ty;
    vector<circle> vc;
    cin >> n;
    cin >> sx >> sy >> tx >> ty;
    ll cs = -1, ct = -1;
    for (ll i = 0; i < n; ++i){
        circle cur;
        cin >> cur.x >> cur.y >> cur.r;
        vc.push_back(cur);
        if (cs == -1 && incirc(sx, sy, vc[i])) cs = i;
        if (ct == -1 && incirc(tx, ty, vc[i])) ct = i;
    }
    
    memset(gc, 0, sizeof(gc));
    for (ll i = 0; i < n; ++i){
        for (ll j = i+1; j < n; ++j){
            if (intersect(vc[i], vc[j])){
                gc[i][j] = 1;
                gc[j][i] = 1;
            }
        }
    }
    cout << (dfs(cs, ct) ? "Yes" : "No") << ende;

    return 0;
}
