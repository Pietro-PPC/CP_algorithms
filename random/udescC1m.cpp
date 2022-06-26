#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 1123

int r, c;
char mat[MAX][MAX];
int dst[MAX][MAX];
int vis[MAX][MAX];

int dir[] = {0, 1, 0, -1, 0};

int bfs(){
    deque<pii> q;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            dst[i][j] = INT_MAX;

    dst[0][0] = 0;
    q.push_back({0, 0});
    while (!q.empty()){
        pii curp = q.front(); q.pop_front();

        for (int i = 1; i < 5; ++i){
            pii nex;
            nex.first = curp.first + dir[i-1];
            nex.second = curp.second + dir[i];
            if (nex.first < 0 || nex.first >= r) continue;
            if (nex.second < 0 || nex.second >= c) continue;

            int w = (mat[curp.first][curp.second] != mat[nex.first][nex.second] ? 1 : 0);
            if (dst[nex.first][nex.second] > dst[curp.first][curp.second]+w){
                dst[nex.first][nex.second] = dst[curp.first][curp.second]+w;
                if (w == 1)
                    q.push_back(nex);
                else
                    q.push_front(nex);
            }
        }
    }
    return dst[r-1][c-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        cin >> r >> c;
        for (int i = 0; i < r; ++i)
            cin >> mat[i];

        cout << bfs() << ende;
        // for (int i = 0; i < r; ++i){ 
        //     for (int j = 0; j < c; ++j)
        //         cout << dst[i][j] << " ";
        //     cout << ende;
        // }
    }

    return 0;
}
