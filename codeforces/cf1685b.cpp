#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0, last = -1;
        int cur, prev;
        cin >> prev;

        for (int i = 1; i < n; ++i){
            cin >> cur;
            if (cur < prev && i >= last+2){
                ans++;
                last = i;
            }
            prev = cur;
        }
        cout << ans << endl;
    }

    return 0;
}
