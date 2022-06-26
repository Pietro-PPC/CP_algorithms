#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

/*def comb(n, k):
    return int(fat[n]/(fat[k]*fat[n-k]))*/

/*
combs = [1]*50
for i in range(2, 50):
    combs[i] = comb(i, i//2)
*/

ll combs[] = {1, 1, 2, 3, 6, 10, 20, 35, 70, 126, 252, 462, 924, 1716, 3432, 6435, 12870, 24310, 48620, 92378, 184756, 352716, 705432, 1352078, 2704156, 5200300, 10400600, 20058300, 40116600, 77558760, 155117520, 300540195, 601080390, 1166803110, 2333606220, 4537567650, 9075135300, 17672631900, 35345263800, 68923264410, 137846528820, 269128937220, 538257874440, 1052049481860, 2104098963720, 4116715363800, 8233430727600, 16123801841550, 32247603683100, 63205303218876, 126410606437752, 247959266474052} ;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t;
    cin >> t;

    while (t--){
        ll n;
        cin >> n;
        
        if (n == 1){
            cout << 0 << ende;
            continue;
        }
        ll ans = upper_bound(combs, combs+52, n) - combs;
        cout << (combs[ans-1] >= n ? ans-1 : ans) << ende;
    }

    return 0;
}
