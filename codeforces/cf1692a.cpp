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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0; 
        if (b > a) ans++;
        if (c > a) ans++;
        if (d > a) ans++;
        cout << ans << ende;
    }

    return 0;
}
