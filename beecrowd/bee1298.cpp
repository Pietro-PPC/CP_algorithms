#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 1123
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3


char barrier[MAX][MAX];
char vis[MAX][MAX];
bool G[MAX][MAX][4];
int n;

void dfs(int i, int j){
    stack<pii> st;
    pii p;
    st.push({i, j});
    while (!st.empty()){
        p = st.top(); st.pop();
        i = p.first;
        j = p.second;

        if (vis[i][j]) continue;
        vis[i][j] = true;
        if (G[i][j][UP])
            st.push({i-1, j});
        if (G[i][j][RIGHT])
            st.push({i, j+1});
        if (G[i][j][DOWN])
            st.push({i+1, j});
        if (G[i][j][LEFT])
            st.push({i, j-1});
    }
}


int diri[] = {0, 0, 1, 1};
int dirj[] = {0, 1, 0, 1};
int dirk1[] = {RIGHT, LEFT, RIGHT, LEFT};
int dirk2[] = {DOWN, DOWN, UP, UP};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n){
        for (int i = 0; i < 2*n-1; ++i)
            cin >> barrier[i];

        for (int i = 0; i < 2*n; ++i)
            for (int j = 0; j < 2*n+1; ++j)
                for (int k = 0; k < 4; ++k)
                    G[i][j][k] = true;

        for (int j = 0; j < 2*n+1; ++j){
            G[0][j][UP] = false;
            G[2*n-1][j][DOWN] = false;
        }

        for (int i = 0; i < 2*n; ++i){
            G[i][0][LEFT] = false;
            G[i][2*n][RIGHT] = false;
        }

        for (int i = 0; i < 2*n-1; ++i){
            for (int j = 0; j < n; ++j){
                if(barrier[i][j] == 'V'){
                    for (int k = 0; k < 4; ++k)
                        G[i+diri[k]][2*j+dirj[k]+i%2][dirk1[k]] = false;
                }
                else {
                    for (int k = 0; k < 4; ++k)
                        G[i+diri[k]][2*j+dirj[k]+i%2][dirk2[k]] = false;
                }
            }
        }

        int ans = -1;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 2*n; i++){
            for (int j = 0; j < 2*n+1; j++){
                if (!vis[i][j]){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}