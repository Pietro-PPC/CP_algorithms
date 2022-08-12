#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 1123

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int a[MAX];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    cout << n/2 << " " << a[n/2] - a[n/2 - 1] << ende;

    return 0;
}
