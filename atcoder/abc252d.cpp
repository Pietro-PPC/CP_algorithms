#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 212345

ll comb33(ll n){
    return (n * (n-1) * (n-2)) / 6;
}
ll comb22(ll n){
    return (n * (n-1)) / 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, occur[MAX], cur;
    cin >> n;
    memset(occur, 0, sizeof(occur));
    for (ll i = 0; i < n; ++i){
        cin >> cur;
        occur[cur]++;
    }
    
    ll ans = (n*(n-1)*(n-2))/6;
    for (ll i = 0; i < MAX; ++i){
        if(occur[i] > 1){
            ans -= (n-occur[i])*comb22(occur[i]) + comb33(occur[i]);
        }
    }
    cout << ans << endl;
    

    return 0;
}
