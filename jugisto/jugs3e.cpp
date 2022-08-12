#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 112345

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<int, int> ma;

    int n, k; cin >> n >> k;
    int a[MAX];
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < k; ++i)
        ans = max(ans, ++ma[a[i]]);

    for (int i = k; i < n; ++i){
        ma[a[i-k]]--;
        ans = max(ans, ++ma[a[i]]);
    }
    cout << ans << endl;

    return 0;
}
