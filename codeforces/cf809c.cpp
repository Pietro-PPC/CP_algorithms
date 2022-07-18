#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_INF 0x7f7f7f7f7f7f7f7f
#define INT_INF 0x7f7f7f7f
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 112345

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int h[MAX];
        for (int i = 0; i < n; ++i){
            cin >> h[i];
        }

        int dif[MAX];
        for (int i = 1; i < n-1; ++i){
            dif[i] = max(h[i-1] - h[i]+1, h[i+1] - h[i] +1);
            dif[i] = max(dif[i], 0);
        }

        ll ans = 0;
        if (n%2){
            for (int i = 1; i < n-1; i += 2) ans += dif[i];
        } else {
            for (int i = 2; i < n-1; i += 2) ans += dif[i];

            ll cur = ans;
            for (int i = 1; i < n-1; i += 2){
                cur = cur - dif[i+1] + dif[i];
                ans = min(ans, cur); 
            }
        }
        cout << ans << ende;
    }

    return 0;
}
