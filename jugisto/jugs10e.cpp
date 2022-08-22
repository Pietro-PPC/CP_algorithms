#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

#define ende "\n"

#define MAX 212345


/*** BEGIN HOPCROFT-KARP ***/

const int L = 2e5+15, R = 2e5+15;
vector<vector<int>> gb (L);
vector<int> matchl (L, -1), matchr (R, -1);

vector<int> dist (L);

bool bfs(int l) {
    queue<int> Q;
    for (int l = 0; l < L; l++)
        if (matchl[l] == -1) { dist[l] = 0; Q.push(l); }
        else { dist[l] = -1; }
    bool ans = false;
    while (!Q.empty()) {
        int l = Q.front(); Q.pop();
        for (auto r : gb[l])
        if (matchr[r] == -1) {
            ans = true;
        } else if (dist[matchr[r]] == -1) {
            dist[matchr[r]] = dist[l] + 1;
            Q.push(matchr[r]);
        }
    }
    return ans;
}

bool dfs(int l) {
    if (l == -1) { return true; }
    for (auto r : gb[l])
        if (matchr[r] == -1 || dist[matchr[r]] == dist[l] + 1)
            if (dfs(matchr[r])) {
                matchr[r] = l;
                matchl[l] = r;
                return true;
            }
    return false;
}

int hkarp(int l) {
    int ans = 0;
    while (bfs(l)){
        for (int u = 0; u < l; u++){
            if (matchl[u] == -1 && dfs(u)) { ans++; }
        }
    }
    return ans; 
}

/*** END HOPCROFT-KARP ***/


vector<char> part(MAX, 0);
vector<int> g[MAX];

void dfs_build(int &l, int &r){
    vector<bool> vis(MAX, false);
    l = 0; r = 0;

    stack<pii> st;
    st.push({0, 0});
    vis[0] = true;
    while(!st.empty()){
        auto [u, pt] = st.top(); st.pop();
        part[u] = pt;
        if (pt == 1) l++;
        else r++;
        for (auto v : g[u])
            if (!vis[v]){
                vis[v] = true;
                int new_pt = pt%2 + 1;
                st.push({v, new_pt});
            }
    }
}

vector<pii> edges;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }

    int l, r;
    dfs_build(l, r);
    for (auto [u, v] : edges){
        if (part[u] == 1) gb[u].push_back(v);
        else gb[v].push_back(u);
    }

    // sort(edges.begin(), edges.end());
    // part[ edges[0].first ] = 1;
    // part[ edges[0].second ] = 2;
    // gb[ edges[0].first ].push_back( edges[0].second );
    // l++; r++;
    // for (int i = 1; i < (int) edges.size(); ++i){
    //     int u = edges[i].first;
    //     int v = edges[i].second;
    //     if ( part[u] == 1 || part[v] == 2 ){
    //         if (part[u] == 0) {part[u] = 1; l++;}
    //         if (part[v] == 0) {part[v] = 2; r++;}
    //         gb[u].push_back(v);
    //     }
    //     else if ( part[u] == 2 || part[v] == 1 ){
    //         if (part[v] == 0) {part[v] = 1; l++;}
    //         if (part[u] == 0) {part[u] = 2; r++;}
    //         gb[v].push_back(u);
    //     }
    // }
    // for (int u = 0; u < n; ++u){
    //     for (auto v : gb[u]){
    //         cout << u << " " << v << endl;
    //     }
    // }
    cout << hkarp(n) << ende;

    return 0;
}
