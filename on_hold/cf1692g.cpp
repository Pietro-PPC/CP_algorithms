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
        int less[MAX], a[MAX];
        int n, k; cin >> n >> k; k++;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n-1; ++i)
            less[i] = (a[i] < 2*a[i+1] ? 1 : 0);
        
        int ans = 0, curqt = 0;
        for (int i = 0; i < k-1; ++i)
            curqt += less[i];
        if (curqt == k-1) ans++;

        for (int i = 1; i <= n-k; ++i){
            curqt -= less[i-1];
            curqt += less[i+k-2];
            if (curqt == k-1) {ans++;}
        }
        cout << ans << ende;
    }

    return 0;
}
