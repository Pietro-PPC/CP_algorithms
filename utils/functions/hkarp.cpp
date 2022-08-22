/*** BEGIN HOPCROFT-KARP ***/

const int L = 1e4+15, R = 1e4+15;
vector<vector<int>> g (L);
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
		for (auto r : g[l])
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
	for (auto r : g[l])
		if (matchr[r] == -1 || dist[matchr[r]] == dist[l] + 1)
			if (dfs(matchr[r])) {
				matchr[r] = l;
				matchl[l] = r;
				return true;
			}
	return false;
}

int hopcroft(int l) {
	int ans = 0;
	while (bfs(l)) 
		for (int u = 0; u < l; u++)
			if (matchl[u] == -1 && dfs(u)) { ans++; }
	return ans; 
}

/*** END HOPCROFT-KARP ***/
