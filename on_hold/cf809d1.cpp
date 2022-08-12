#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_INF 0x7f7f7f7f7f7f7f7f
#define INT_INF 0x7f7f7f7f
#define ende "\n"

#define MP make_pair
#define PB push_back

#define INF 1123456789
#define MAX 3123

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        int a[MAX];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a+n);

        int gr = a[n-1]/k;
        int le = gr;
        int bst;
        for (int i = n-2; i >= 0 ; --i){
            bst = a[i];
            for (int j = 2; j <= k; ++j){
                int cur = a[i]/j;
                if ( max(abs(cur-le), abs(cur-gr)) <= max(abs(bst-le), abs(bst-gr))){
                    bst = cur;
                }
            }
            if (bst < le) le = bst;
            if (bst > gr) gr = bst;
        }
        cout << gr - le << ende;
    }

    return 0;
}
