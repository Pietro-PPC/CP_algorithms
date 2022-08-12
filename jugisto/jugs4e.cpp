#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 11234
#define INF 912345678
int n, k, c;
int a[MAX], rsum[MAX];
int memo[MAX][MAX];
int min_sum(int ini, int npencils){

    // out of pencils
    if (npencils == 0)
        return 0;

    // no more space left
    if ((ini >= n+1-c) || (n+1-c - ini < (npencils-1)*c+1)) 
        return INF;
    
    if (memo[ini][npencils] < INF)
        return memo[ini][npencils];
    // cout << ini << " " << npencils << ende;

    int op1 = min_sum(ini+c, npencils-1) + rsum[ini];
    int op2 = min_sum(ini+1, npencils);
    // if (op1 <= op2)
    //     cout << ini << " " << rsum[ini] << " " << npencils << ende;
    return memo[ini][npencils] = min(op1, op2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int total_sum;
    while (cin >> n >> k >> c){
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        

        rsum[0] = a[0];
        for (int i = 1; i < c; ++i)
            rsum[0] += a[i];

        total_sum = rsum[0];
        for (int i = 1; i <= n-c; ++i){
            rsum[i] = rsum[i-1] + a[i+c-1] - a[i-1];
            total_sum += a[i+c-1];
        }
        memset(memo, 0x3f, sizeof(memo));
        cout << total_sum - min_sum(0, k) << ende;

    }

    // for (int i = 0; i <= n-c; ++i)
    //     cout << rsum[i] << " ";
    // cout << ende;

    return 0;
}
