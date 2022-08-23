#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define ende "\n"

const int L = log2(N);

const MAX = 11234;

vector<pii> g(MAX);
vector<int> depth (N, 0);
vector<vector<int>> weiop (N, vector<int>(L+1));
vector<vector<int>> up (N, vector<int>(L+1));

void bl_euler_tour(int u, int p, int w) {
	up[u][0] = p; weiop[u][0] = w; depth[u] = depth[p] + 1;

	for (auto [v, w] : g[u]) if (v != p)
		bl_euler_tour(v, u, w);
}

void bl_init(int u, int n) {
	depth[u] = 0; bl_euler_tour(u, u, 0);
	for (int l = 0; l < L; l++){
		cout << "l = " << l << ende;
		for (int u = 0; u < n; u++) {
			cout << "u = " << u << " | ";
			int a = up[u][l];
			up[u][l+1] = up[a][l];
			weiop[u][l+1] = OP(weiop[u][l], weiop[a][l]);
			cout << up[u][l+1] << " " << weiop[u][l+1];
		}
		cout << ende;
	}
}

int bl_lca(int a, int b) {
	if (!(depth[b] < depth[a])) { swap(a, b); }
	int diff = depth[a] - depth[b];
	
	for (int l = L; l >= 0; l--) 
		if (diff & (1 << l))
			a = up[a][l];

	if (a == b) { return a; }
	
	for (int l = L; l >= 0; l--) 
		if (up[a][l] != up[b][l])
			a = up[a][l], b = up[b][l];

	return up[a][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i){
    	int u, v, w;
    	cin >> u >> v >> w;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    bl_init(1, 2);

    return 0;
}

