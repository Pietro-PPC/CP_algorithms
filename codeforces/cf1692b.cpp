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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int has[MAX];
        memset(has, 0, sizeof(has));
        int n; cin >> n;
        int cur, ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> cur;
            if (!has[cur]){
                has[cur] = 1;
                ans++;
            }
        }
        if (ans %2 != n%2) ans--;
        cout << ans << ende;
    }

    return 0;
}
