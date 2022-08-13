/*** BEGIN KORASAJU ***/

vector<int> comps(MAX, -1), vis(MAX, 0);
stack<int> st;
void fill_stack(int src){
    if (vis[src]) return;
    vis[src] = 1;
    for (auto v : g_t[src]) fill_stack(v);
    st.push(src);
}

void mark_comp(int u, int num){
    if (comps[u] != -1) return;
    comps[u] = num;
    for (auto v : g[u]) mark_comp(v, num);
}

void korasaju(){
    for (int u = 0; u < n; ++u) fill_stack(u);
    while (!st.empty()){ 
        int u = st.top(); st.pop(); 
        mark_comp(u, u); 
    }
}

/*** END KORASAJU ***/