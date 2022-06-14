#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 212345

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int n, s; cin >> n >> s;
        int a[MAX], pref[MAX], suf[MAX];
        for (int i = 0; i < n; ++i) cin >> a[i];

        pref[0] = a[0];        
        for (int i = 1; i < n; ++i) pref[i] = pref[i-1] + a[i];
        suf[n-1] = a[n-1];
        for (int i = n-2; i >= 0; --i) suf[i] = suf[i+1] + a[i];

        int ones = pref[n-1] - s;
        if (ones < 0){
            cout << -1 << ende; continue;
        } else if (ones == 0){
            cout << 0 << ende; continue;
        }

        int le = lower_bound(pref, pref+n, ones) - pref;
        int ri = n-1;
        int ans = le+1;
        // cout <<"os oness" << " " << ones << " " << pref[le] << ende;
        while (le > 0){
            le--;
            while (pref[le]+suf[ri] != ones) ri--;
            ans = min(ans, (le+1) + (n-ri));
        }
        if (pref[0] == 0)
            ans = min(ans, n-ri);
        cout << ans << ende;
        
    }

    return 0;
}
