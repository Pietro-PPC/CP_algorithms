#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

ll count (ll a, ll b, ll val){
    ll ini = a;
    if (a%val)
        ini = a + (val - (a%val));
    
    if (ini > b) return 0;
    return (b-ini)/val + 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b; cin >> a >> b;
    int n; cin >> n;
    
    ll primos[20];
    for (int i = 0; i < n; ++i)
        cin >> primos[i];

    ll mask = 0;
    for (int i = 0; i < n; ++i){
        mask <<= 1;
        mask += 1;
    }

    ll ans = b+1-a;
    for (ll ss = mask; ss > 0; ss = (ss-1) & mask ){
        ll prod = 1;
        int elems = 0;
        for (ll sss = 1, i = 0; sss < 1<<n; sss <<= 1, i++){
            if (ss & sss) {
                prod *= primos[i];
                elems++;
            }
        }
        ll curval = count(a, b, prod);
        if (elems%2 == 0) curval *= -1;
        ans -= curval;
    }
    cout << ans << ende;

    return 0;
}
