#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 51

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        bool ans = false;
        int n; cin >> n;
        int a[MAX];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 0; i < n; ++i){
            int sum = 0;
            for (int j = 0; j < i; ++j)
                sum += a[j];
            for (int j = i+1; j < n; ++j)
                sum += a[j];
            if ((sum % (n-1)) == 0 && (sum/(n-1) == a[i]))
                ans = true;
        }
        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
