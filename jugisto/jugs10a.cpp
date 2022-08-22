#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

#define ende "\n"

#define MAX 212345
#define INF 1123456789

const int L = log2(INF);

int cts = 1;
vector<int> t(MAX);
vector<vector<int>> cycles;
vector<pii> cycle(MAX, pii{-1, -1});
vector<int> vis(MAX, 0);

vector<vector<int>> up(MAX, vector<int>(L));

void cycle_dfs(int st){
    int cur = st;
    while (!vis[cur]){
        vis[cur] = cts;
        cur = t[cur];
    }

    if (vis[cur] == cts){ // temos um ciclo!
        vector<int> new_cycle;
        int ind_cycle = cycles.size();
        int cycle_start = cur;
        
        new_cycle.push_back(cur);
        cycle[cur] = {ind_cycle, 0};
        cur = t[cur];

        for (int i = 1; cur != cycle_start; cur = t[cur], ++i){
            new_cycle.push_back(cur);
            cycle[cur] = {ind_cycle, i};
        }
        // for (auto u : new_cycle) cout << u << " " ;
        // cout << ende;
        cycles.push_back(new_cycle);
    }
}


vector<int> g_t[MAX];
stack<int> st;
void dfs_topo(int src) {
    stack<pii> v_st;

    v_st.push({src, -1});
    vis[src] = 1;
    while (!v_st.empty()){
        auto [u, p] = v_st.top(); v_st.pop();
        if (u == -1) {st.push(p); continue;}
        
        v_st.push({-1, u});
        for (int v : g_t[u]) { 
            if (!vis[v]){
                vis[v] = 1;
                v_st.push({v, u}); 
            }
        }
    }
}

vector<int> toposort(int n) {
    vector<int> topo;
    for (int u = 0; u < n; u++) { 
        if (cycle[u].first == -1)
            dfs_topo(u); 
    }
    while (!st.empty()) { 
        int v = st.top(); st.pop();
        topo.push_back(v); 
    }
    return topo; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // processar entrada
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i)
        { cin >> t[i]; t[i]--; }

    // O(V+E)
    // achar ciclos, preencher propriedades de vertices em ciclo 
    for (int u = 0; u < n; ++u) {
        if (!vis[u]) {cycle_dfs(u); cts++;}
    }
    // O(V+E)
    // preencher up de vertices em ciclo
    for (int u = 0; u < n; ++u){
        int cycle_ind = cycle[u].first;
        int cycle_pos = cycle[u].second;
        if (cycle_ind == -1 && cycle_pos == -1) continue;

        for (int i = 0; i < L; ++i){
            int ind = ( cycle_pos + (1 << i) ) % cycles[ cycle_ind ].size();
            up[u][i] = cycles[ cycle_ind ][ ind ];
        }
    }


    // O(V+E)
    // transpor grafo
    for (int u = 0; u < n; ++u)
        g_t[ t[u] ].push_back(u);

    // O(V+E)
    // Ordenação topológica do grafo transposto 
    vis.assign(MAX, 0);
    vector<int> topo = toposort(n);
    // for (auto u : topo) cout << u << " ";
    //     cout << ende;

    // O(V)
    // preencher up de vertices fora de ciclo
    for (auto u : topo){
        up[u][0] = t[u];
        for (int i = 1; i < L; ++i){
            up[u][i] = up[ up[u][i-1] ][i-1];
        }
    }

    // for (int u = 0; u < n; ++u){
    //     for (int i = 0; i < 4; ++i){
    //         cout << up[u][i] << " ";
    //     }
    //     cout << endl;
    // }

    // O(Q)
    // responder queries
    while (q--){
        int x, k; cin >> x >> k;

        int i = 0;
        int it = --x;
        while (k){
            if (k%2) it = up[it][i];

            i++;
            k/=2;
        }
        cout << it+1 << endl;
    }

    return 0;
}
