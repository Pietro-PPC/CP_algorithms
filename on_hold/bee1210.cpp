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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, I, m, p;
    while (cin >> n >> I >> m >> p){
        int cost[MAX], sell[MAX];
        for (int i = 0; i < m; ++i)
            cin >> cost[i];
        for (int i = 1; i <= m; ++i)
            cin >> sell[i];
        
        ll dp[2][MAX];
        int age[2][MAX];
        int prnt[2][MAX];
        dp[0][0] = 0;
        dp[1][0] = 0;
        age[0][0] = I-1;
        age[1][0] = I-1;
        for (int i = 1; i <= n; ++i){
            ll fi, se;

            fi = dp[0][i-1] + p+cost[0] - sell[ age[0][i-1]+1 ];
            se = dp[1][i-1] + p+cost[0] - sell[ age[1][i-1]+1 ];
            dp[0][i] = min(fi, se);
            age[0][i] = 0;
            prnt[0][i] = (dp[0][i] == fi ? 0 : 1);

            fi = (age[0][i-1]+1 < m ? dp[0][i-1] + cost[ age[0][i-1]+1 ] : LL_MAX);
            se = (age[1][i-1]+1 < m ? dp[1][i-1] + cost[ age[1][i-1]+1 ] : LL_MAX);
            dp[1][i] = min(fi, se);
            age[1][i] = (dp[1][i] == fi ? age[0][i-1] : age[1][i-1]) + 1  ;
            prnt[1][i] = (dp[1][i] == fi ? 0 : 1);
        }
        cout << min(dp[0][n], dp[1][n]) << endl;
        stack<int> path;
        int cur = (dp[0][n] < dp[1][n] ? 0 : 1);
        if (cur == 0) path.push(n);
        for (int i = n-1; i > 0; --i){
            cur = prnt[cur][i+1];
            if (cur == 0) path.push(i);
        }
        if (path.empty())
            cout << 0 << ende;
        else{
            while (!path.empty()){
                cout << path.top() << " "; path.pop();
            }
            cout << ende;
        }
    }

    return 0;
}
