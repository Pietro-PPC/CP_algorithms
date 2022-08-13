#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

#define ende "\n"

#define MAX 212345


/*** BEGIN KUHN ***/
int cts = 1;
const int L = MAX;
const int R = MAX;

vector<vector<int>> g(L);
vector<int> matchr (R, -1);
vector<int> vis(MAX, 0);
int dfs(int u) {
    if (vis[u] == cts) { return 0; }
    vis[u] = cts;
    for (int v : g[u])
        if (matchr[v] == -1 || dfs(matchr[v])) 
            {matchr[v] = u; return 1;}
    return 0;
}

int kuhn(int l) {
    int ans = 0;
    for (int u = 0; u < l; u++) { ans += dfs(u); cts++; }
    return ans;
}
/*** END KUHN ***/

vector<int> g_t[MAX];
map<int, int> m_l, m_r;
void build_g(int &l, int &r){
    queue<pii> q;

    vector<bool> visbg(MAX, false);
    q.push({0, 0});
    visbg[0] = true;
    m_l[0] = l++;
    while (!q.empty()){
        auto [u, lvl] = q.front(); q.pop();

        for (auto v : g_t[u]){
            // cout << v << ende;
            if (!visbg[v]){

                q.push({v, lvl+1});
                visbg[v] = true;
                if (lvl%2) 
                    { m_l[v] = l++; // cout << v << " = l " << l-1 << endl;
                }
                else 
                    { m_r[v] = r++; // cout << v << " = r " << r-1 << endl;
                }

            }
            if (lvl%2) { //cout << m_l[v]  << " -> " << m_r[u] << ende; 
                g[ m_l[v] ].push_back(m_r[u]); }
            else { //cout << m_l[u] << " -> " << m_r[v] << ende; 
                g[ m_l[u] ].push_back(m_r[v]); }
        }

    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v; u--; v--;
        g_t[u].push_back(v);
        g_t[v].push_back(u);
    }

    int l = 0, r = 0;
    build_g(l, r);

    cout << kuhn(l) << ende;

    return 0;
}
