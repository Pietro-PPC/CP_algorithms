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
    
    int n; cin >> n;
    list<int> fita;
    auto it = fita.end();
    while (n--){
        char op; cin >> op;
        if (op == 'm'){
            int d; cin >> d;
            while (d){ 
                d<0 ? it-- : it++; 
                d += (d>0 ? -1 : 1);
            }
        } else if (op == 'i'){
            int q, t; cin >> q >> t;
            while (q--) {fita.insert(it, t); it--;}
        } else if (op == 'q'){
            cout << *it << endl;
        }
        else if (op == 'd'){
            auto cp = it++;
            fita.erase(cp);
        }
    }


    return 0;
}
