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