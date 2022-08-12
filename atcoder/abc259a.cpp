#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7f7f7f7f7f7f7f7f
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 112

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    int hei[MAX];
    hei[n] = t;
    for (int i = n-1; i >= 0; --i){
        int sub = i < x ? d : 0;
        hei[i] = hei[i+1] - sub;
    }
    cout << hei[m] << ende;

    return 0;
}
