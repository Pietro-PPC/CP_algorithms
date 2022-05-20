#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112

bool vis[MAX][MAX][MAX];
int dst[MAX][MAX][MAX];
int N, M, L;

bool valid(int i, pii jk){
    return (i >= 0 && i < N 
        && jk.first >= 0 && jk.first < M 
        && jk.second >= 0 && jk.second < L
    );
}

int bfs(pair<int, pii> p1, pair<int, pii> p2){
    queue<pair<int, pii>> Q;
    memset(dst, -1, sizeof(dst));
    int ret = -1;

    bool found = false;
    dst[p1.first][p1.second.first][p1.second.second] = 0;
    Q.push(p1);
    while (!Q.empty()){
        auto[i, jk] = Q.front(); Q.pop();
        if (!valid(i, jk) || vis[i][jk.first][jk.second] || found)
            continue;
        
        int curDst = dst[i][jk.first][jk.second];
        if (i == p2.first && jk == p2.second){
            found = true;
            ret = curDst;
            continue;
        }

        cout << i << " " << jk.first << " " << jk.second << endl;
        vis[i][jk.first][jk.second] = true;

        for (int di = 2; di >= -2; di--){
            int dj = 3-abs(di);
            if (di){
                Q.push({i+di, { jk.first+dj, jk.second }});
                Q.push({i+di, { jk.first-dj, jk.second }});
                if (valid(i+di, { jk.first+dj, jk.second }))
                    dst[i+di][jk.first+dj][jk.second] = curDst+1;
                if (valid(i+di, { jk.first-dj, jk.second }))
                    dst[i+di][jk.first-dj][jk.second] = curDst+1;
            }
        }

        for (int dj = 2; dj >= -2; dj--){
            int dk = 3-abs(dj);
            if (dj){
                Q.push({i, { jk.first+dj, jk.second+dk }});
                Q.push({i, { jk.first+dj, jk.second-dk }});
                if (valid(i, { jk.first+dj, jk.second+dk }))
                    dst[i][jk.first+dj][jk.second+dk] = curDst+1;
                if (valid(i, { jk.first+dj, jk.second-dk }))
                    dst[i][jk.first+dj][jk.second-dk] = curDst+1;
            }
        }
        
        for (int dk = 2; dk >= -2; dk--){
            int di = 3-abs(dk);
            if (dk){
                Q.push({i+di, { jk.first, jk.second+dk }});
                Q.push({i-di, { jk.first, jk.second+dk }});
                if (valid(i+di, { jk.first, jk.second+dk }))
                    dst[i+di][jk.first][jk.second+dk] = curDst+1;
                if (valid(i-di, { jk.first, jk.second+dk }))
                    dst[i-di][jk.first][jk.second+dk] = curDst+1;
            }
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int i1, i2, j1, j2, k1, k2;
    pair<int, pii> p1, p2;
    cin >> N >> M >> L;
    cin >> p1.first >> p1.second.first >> p1.second.second;
    cin >> p2.first >> p2.second.first >> p2.second.second;

    memset(vis, 0, sizeof(vis));
    cout << bfs(p1, p2) << endl;


    return 0;
}
