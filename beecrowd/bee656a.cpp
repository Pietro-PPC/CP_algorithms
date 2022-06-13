#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

bool bsearch(ll num){
    ll lo = 0, hi = 5123456789;
    while (lo < hi){
        ll mid = lo + (hi-lo)/2;
        // cout << mid << endl;
        if (mid*mid < num)
            lo = mid+1;
        else 
            hi = mid;
    }
    return (lo*lo == num);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b, c;
    cin >> a >> b >> c;
    ll dlt = b * b - (4 * a * c);

    cout << (bsearch(dlt) ? "Y\n" : "N\n");

    return 0;
}
