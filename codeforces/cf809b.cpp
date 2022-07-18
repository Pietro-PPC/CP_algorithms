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

struct color{
    pair<int, int> last_ev;
    pair<int, int> last_od;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int c[MAX];
        for (int i = 0; i < n; ++i)
            {cin >> c[i]; c[i]--;}
        color towcnt[MAX];
        for (int i = 0; i < n; ++i){
            towcnt[i].last_ev.first = -1; 
            towcnt[i].last_ev.second = 0;
            towcnt[i].last_od.first = -1; 
            towcnt[i].last_od.second = 0;
        }

        for (int i = 0; i < n; ++i){
            if (i%2 == 0){
                // if (towcnt[c[i]].last_od.first == -1)
                towcnt[c[i]].last_ev.first = i;
                towcnt[c[i]].last_ev.second = towcnt[c[i]].last_od.second + 1;
            }
            else{
                towcnt[c[i]].last_od.first = i;
                towcnt[c[i]].last_od.second = towcnt[c[i]].last_ev.second + 1;
            }
        }
        for (int i = 0; i < n; ++i){
            cout << max(towcnt[i].last_od.second, towcnt[i].last_ev.second) << " ";
        }
        cout << ende;
    }

    return 0;
}
