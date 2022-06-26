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
    
    int t; cin >>t;
    while (t--){
        double n;
        cin >> n;
        n*=10;
        double ans = floor((500-6*n)/4)/10;
        cout << setprecision(1) << fixed << ans << ende;
    }

    return 0;
}
