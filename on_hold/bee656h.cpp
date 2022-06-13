#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 1030

char grid[MAX][MAX];
char colorgrid[MAX][MAX];
int n, m;

int adjv[4] = {1, -1, 0,  0};
int adjh[4] = {0,  0, 1, -1};

void bfs(int color, int l, int c){
    queue<pii> q;
    
    q.push({l, c});
    colorgrid[l][c] = color;
    while (!q.empty()){
        auto &[i, j] = q.front(); q.pop();
        for (int it = 0; it < 4; ++it){
            int nexti = i+adjv[it], nextj = j+adjh[it];
            if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < m
                && !colorgrid[nexti][nextj]){
                q.push({nexti, nextj});
                colorgrid[nexti][nextj] = color;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i){
        cin >> grid[i];
        for (int j = 0; j < m; ++j){
            if (grid[i][j] == '.') colorgrid[i][j] = 0;
            else colorgrid[i][j] = -1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(!colorgrid[i][j]){
                bfs(++cnt, i, j);
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
