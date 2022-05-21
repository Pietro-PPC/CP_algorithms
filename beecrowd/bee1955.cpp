#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 1123

bool G[MAX][MAX];
int n;
int color[MAX];

bool dfs(int st, int c){
    if (color[st])
        return color[st] == c;
    
    color[st] = c;
    int ret = true;
    for (int i = 0; i < n; ++i){
        if (G[st][i])
            ret = ret && dfs(i, (c%2)+1);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> G[i][j];
            G[i][j] = !G[i][j];
        }
    }

    bool ans = true;
    memset(color, 0, sizeof(color));
    for (int i = 0; i < n; ++i){
        if (!color[i])
            ans = ans && dfs(i, 1);
    }
    cout << (ans ? "Bazinga!" : "Fail!") << endl;

    return 0;
}
