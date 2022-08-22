#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

#define ende "\n"

#define N 512
struct edge { ll u, v, cap; }; vector<edge> edges;
vector<vector<ll>> res (N);

/*** BEGIN FFEK ***/

#define INF 1123456789

vector<ll> ix (N), dist (N), par (N);
bool minimum_path(ll s, ll t) {

	fill(dist.begin(), dist.end(), INF); dist[s] = 0;
	queue<ll> q; q.push(s);
	while (!q.empty()) {
		ll u = q.front(); q.pop();
		if (u == t) { break; }
		for (ll i : res[u]) {
			edge e = edges[i]; ll v = e.v;
			if (e.cap && dist[v] == INF) {
				dist[v] = dist[u] + 1;
				par[v] = u; ix[v] = i;
				q.push(v);
			}
		}
	}
	return dist[t] < INF;
}

pair<ll, ll> ffek(ll s, ll t) {
	ll min_cost = 0, max_flow = 0;
	while (minimum_path(s, t)) {
		ll flow = INF;
		for (ll u = t; u != s; u = par[u]) {
			flow = min(flow, edges[ix[u]].cap);
		}
		for (ll u = t; u != s; u = par[u]) {
			edges[ix[u] ].cap -= flow;
			edges[ix[u]^1].cap += flow;
		}
		min_cost += flow * dist[t];
		max_flow += flow;
	}
	return { min_cost, max_flow };
}

/*** END FFEK ***/


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m; cin >> n >> m;
    for (ll i = 0; i < m; ++i){
    	ll u, v;
    	cin >> u >> v; u--; v--;
    	res[u].push_back(edges.size()); edges.push_back({u, v, 1});
    	res[v].push_back(edges.size()); edges.push_back({v, u, 1});
    }

    auto [min_cost, max_flow] = ffek(0, n-1);
    cout << max_flow << ende;

    return 0;
}
