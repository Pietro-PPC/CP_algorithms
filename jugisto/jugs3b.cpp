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
const int MOD = 1e9 + 7;

ll fatorial[MAX];

void fat(ll a){
    fatorial[0] = fatorial[1] = 1;
    for (int i = 2; i <= a; ++i)
        fatorial[i] = (fatorial[i-1]*i) % MOD;
}

ll expbin(ll a, ll b){
    if (b == 0) return 1;
    if (b == 1) return a;

    ll ret = expbin(a, b/2);
    ret = (ret*ret)%MOD;
    if (b%2) ret = (ret*a)%MOD;
    return ret;
}

ll comb (ll a, ll b){
    ll num = fatorial[a];
    ll den = expbin(fatorial[a-b], MOD-2);
    return (num*den) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, cors; cin >> n >> cors;
    int b[MAX];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    int cor[MAX];
    memset(cor, 0, sizeof(cor));
    for (int i = 0; i < cors; ++i){
        int l, c; cin >> l >> c;
        cor[c-1]++;
    }
    fat(10000);

    ll ans = 1;
    for (int i = 0; i < n; ++i)
        ans = (ans * comb(b[i], n-cor[i]))%MOD;

    cout << ans << endl;

    return 0;
}
