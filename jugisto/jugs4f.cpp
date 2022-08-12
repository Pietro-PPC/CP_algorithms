#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 2123
#define INF 112345678

int n, l, m, p;
int c[MAX], v[MAX];
ll dp[MAX][MAX];
vector<int> opt_path;

ll price(int y, int a){
    if (y > n) return 0;
    if (dp[y][a] != -1) return dp[y][a];

    ll op1 = a < m ? c[a] + price(y+1, a+1) : INF;
    ll op2 = p - v[a] + c[0] + price(y+1, 1);
    return dp[y][a] = min(op1, op2);
}

void calc_path(int y, int a){
    if (y > n) return;

    ll op1 = a < m ? c[a] + price(y+1, a+1) : INF;
    ll op2 = p - v[a] + c[0] + price(y+1, 1);
    if (op2 <= op1){
        opt_path.push_back(y);
        calc_path(y+1, 1);
    }
    else
        calc_path(y+1, a+1);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n >> l >> m >> p){
        for (int i = 0; i <  m; ++i) cin >> c[i];
        for (int i = 1; i <= m; ++i) cin >> v[i];

        memset(dp, -1, sizeof(dp));
        cout << price(1, l) << ende;

        opt_path.clear();
        calc_path(1, l);
        
        if (opt_path.size()){
            int size = opt_path.size();
            for (int i = 0; i < size-1; ++i) 
                cout << opt_path[i] << " ";
            cout << opt_path[size-1] << ende;
        }
        else 
            cout << 0 << ende;
    }

    return 0;
}