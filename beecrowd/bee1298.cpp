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

        for (int i = 0; i < 2*n-1; i+=2){
            for (int j = 0; j < n; ++j){
                if(barrier[i][j] == 'V'){
                    G[i][2*j][RIGHT] = false;
                    G[i][2*j+1][LEFT] = false;
                    G[i+1][2*j][RIGHT] = false;
                    G[i+1][2*j+1][LEFT] = false;
                }
                else {
                    G[i][2*j][DOWN] = false;
                    G[i][2*j+1][DOWN] = false;
                    G[i+1][2*j][UP] = false;
                    G[i+1][2*j+1][UP] = false;
                }
            }
        }

        for (int i = 1; i < 2*n-1; i+=2){
            for (int j = 0; j < n; ++j){
                if(barrier[i][j] == 'V'){
                    G[i][2*j+1][RIGHT] = false;
                    G[i][2*j+2][LEFT] = false;
                    G[i+1][2*j+1][RIGHT] = false;
                    G[i+1][2*j+2][LEFT] = false;
                }
                else {
                    G[i][2*j+1][DOWN] = false;
                    G[i][2*j+2][DOWN] = false;
                    G[i+1][2*j+1][UP] = false;
                    G[i+1][2*j+2][UP] = false;
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