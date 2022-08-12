#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 15

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    ll q = min(a[1]/a[0], a[2]/a[1]);
    int dif = -1;
    for (int i = 1; i < n; i++)
        if (a[i]/a[i-1] > q) dif = i;

    if (dif == -1){
        if (a[0] % q == 0 && q > 1)
            cout << a[0]/q << ende;
        cout << a[n-1]*q << ende;
    } else{
        cout << a[dif-1]*q << ende;
    }

    return 0;
}
