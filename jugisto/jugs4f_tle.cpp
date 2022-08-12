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

#define SELL 1
#define NOTS 2
#define BOTH 3

int n, l, m, p;
int c[MAX], v[MAX];
ll dp[MAX][MAX], ans;
vector<int> cur_path, opt_path;
int child[MAX][MAX];

bool better_path(vector<int> &a, vector<int> &b){
    if (a.size() > b.size()) return true;
    if (a.size() < b.size()) return false;

    int len = min(a.size(), b.size());
    for (int i = 0; i < len; ++i){
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;
    }

    return false;
}

void calc_path(int y, int a){
    if (y > n){
        if (better_path(cur_path, opt_path))
            opt_path = cur_path;
        return;
    }

    if (child[y][a] & SELL){
        cur_path.push_back(y);
        calc_path(y+1, 1);
        cur_path.pop_back();
    }
    if (child[y][a] & NOTS)
        calc_path(y+1, a+1);
}

ll price(int y, int a){
    if (y > n) return 0;
    if (dp[y][a] != -1) return dp[y][a];

    ll op1 = a < m ? c[a] + price(y+1, a+1) : INF;
    ll op2 = p - v[a] + c[0] + price(y+1, 1);

    dp[y][a] = min(op1, op2);
    if (op1 == op2)
        child[y][a] = BOTH;
    else if (dp[y][a] == op1)
        child[y][a] = NOTS;
    else
        child[y][a] = SELL;

    return dp[y][a];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n >> l >> m >> p){
        for (int i = 0; i <  m; ++i) cin >> c[i];
        for (int i = 1; i <= m; ++i) cin >> v[i];

        memset(dp, -1, sizeof(dp));
        ans = price(1, l);
        cout << ans << ende;

        opt_path.clear();
        cur_path.clear();
        calc_path(1, l);
        
        for (auto &it : opt_path) cout << it << " ";
        cout << ende;

        // for (int i = 1; i <= n; ++i){
        //     for (int j = 1; j <= m; ++j)
        //         cout << dp[i][j] << " ";
        //     cout << ende;
        // }
        // cout << ende;
        // for (int i = 1; i <= n; ++i){
        //     for (int j = 1; j <= m; ++j)
        //         cout << child[i][j] << " ";
        //     cout << ende;
        // }
        // cout << ende;

    }

    return 0;
}
