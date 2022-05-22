#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 1123

char note[MAX];
bool vis[MAX];

bool dfs(vector<vector<int>> G, int t){
    int cntb = 0;
    stack<int> st;

    st.push(t);
    while(!st.empty()){
        int cur = st.top(); st.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        if (note[cur] == 'B') cntb++;
        for (auto next : G[cur]){
            st.push(next);
        }
    }
    return (cntb % 2) == 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, b;
    while (cin >> n >> m ){
        for (int i = 1; i <= n; ++i){
            cin >> note[i];
        }
        vector<vector<int>> G(MAX);
        for (int i = 0; i < m; ++i){
            cin >> a >> b;
            G[a].PB(b);
            G[b].PB(a);
        }
        bool ans = true;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i){
            if (!vis[i])
                ans = ans && dfs(G, i);
        }
        cout << (ans ? "Y" : "N") << endl;
    }

    return 0;
}
