#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        ll n, m; cin >> n >> m;
        ll ans = ((1+m)*m)/2 + ((m+n*m)*n)/2 - m;
        cout << ans << endl;
    }

    return 0;
}
