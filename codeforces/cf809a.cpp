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

#define MAX 112345

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        int a[MAX];
        for (int i = 0; i < n; ++i)
            {cin >> a[i]; a[i]--;}
        string s(m, 'B');

        for (int i = 0; i < n; ++i){
            int newa = min(a[i], m-a[i]-1);
            if (s[newa] == 'A')
                newa = m-newa-1;
            s[newa] = 'A';
        }
        cout << s << ende;
    }

    return 0;
}
