#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112345

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int a[MAX];
        int ans[MAX];
        int n; cin >> n;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        if (n%2 == 1){
            cout << "NO" << endl;
            continue;
        }

        sort(a, a+n);
        int half = n/2;
        bool ok = true;
        ans[0] = a[0];
        ans[1] = a[half];
        for (int i = 1; i < half; i++){
            ans[2*i] = a[i];
            ans[(2*i)+1] = a[half+i];
            if (ans[2*i] == ans[2*i-1] || ans[2*i] == ans[2*i+1])
                ok = false;
        }
        ans[2*half] = a[0];
        ans[2*half+1] = a[half];
        if (ans[n] == ans[n-1] || ans[n] == ans[n+1]){
            ok = false;
        }

        if (!ok){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i)
                cout << ans[i] << " ";
            cout << endl;
        }


    }

    return 0;
}
