#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define INF 11234567

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    while(n){
        int best = -INF;
        int curSum = 0;
        for (int i = 0; i < n; ++i){
            int cur; cin >> cur;
            curSum += cur;
            best = max(best, curSum);
            if (curSum < 0)
                curSum = 0;
        }
        if (best > 0)
            cout << "The maximum winning streak is " << best << ".\n";
        else
            cout << "Losing streak.\n";
        cin >> n;
    }
    return 0;
}
