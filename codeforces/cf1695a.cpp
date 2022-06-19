#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        int lin=-1, col=-1, ma = INT_MIN;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                int aux; cin >> aux;
                if (aux > ma){
                    ma = aux;
                    lin = i;
                    col = j;
                }
            }
        }
        int hei, wid;
        hei = max(lin+1, n-lin);
        wid = max(col+1, m-col);
        cout << hei*wid << endl;
    }

    return 0;
}
