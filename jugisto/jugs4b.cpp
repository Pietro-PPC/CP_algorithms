#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 31234

int coins[] = {1, 5, 10, 25, 50};
ll ways[5][MAX];

ll count(int m, ll n){
    if (m < 0 || n < 0) return 0;
    if (m == 0 || n == 0){
        ways[m][n] = 1; 
        return 1;
    }
    if (ways[m][n] == -1)
        ways[m][n] = count(m-1, n) + count(m, n-coins[m]);
    return (ways[m][n]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    memset(ways, -1, sizeof(ways));
    while (cin >> n)
        cout << count(4, n) << ende;

    return 0;
}
