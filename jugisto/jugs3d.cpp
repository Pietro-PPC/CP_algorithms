#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 11234567

vector<bool> sieve(MAX, true);

void build(int qt){
    for (int i = 2; i <= qt; ++i){
        if (sieve[i])
            for (int j = 2*i; j <= qt; j+=i)
                sieve[j] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    build(10000001);
    int ans = 0;
    for (int i = 2; i <= n/2; ++i){
        if (sieve[i] && sieve[n-i]) ans++;
    }
    cout << ans << ende;

    return 0;
}
