#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

#define ende "\n"
#define LOG false

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q; cin >> n >> q;

    const int N = 2e5+15, B = ceil(sqrt(N));
    if (LOG) cout << B << endl << endl;
    list<int> l; vector<int> bsz (N/B + 1);
    vector<list<int>::iterator> bbegin (N/B + 1);
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x; 
        auto ins = l.insert(l.end(), x);
        if (i % B == 0) 
            { bbegin[i/B] = ins; }
        bsz[i/B]++; 
    }

    if (LOG) cout << "size " << bbegin.size() << ende;
    int pos = 0;
    while (q--) {
        char op; cin >> op;
        if (LOG) cout << "Operador " << op << endl;

        if (op == 'm'){
            int delta; cin >> delta;
            pos += delta;
        } else if (op == 'i') {
            int val; cin >> val;

            auto it = bbegin[pos/B];
            advance(it, pos%B);
            l.insert(it, val);
            if (pos % B == 0) { bbegin[pos/B]--; }
            
            int bi = pos/B;
            while (bsz[bi+1] == B) 
                { bbegin[bi+1]--; bi++; }
            if (bsz[bi+1] == 0){
                bsz[bi+1] = 1;
                bbegin[bi+1] = l.end();
                bbegin[bi+1]--;
            } else 
                { bsz[bi+1]++; bbegin[bi+1]--; }

        } else if (op == 'd') {

            auto it = bbegin[pos/B];
            advance(it, pos%B);
            if (pos % B == 0) { bbegin[pos/B]++; }

            l.erase(it);
            int bi = pos/B;
            if (LOG) cout << "Bi " << bi << endl;
            while (bsz[bi+1] > 0) 
                { bbegin[bi+1]++; bi++; }
            if (LOG) cout << "delete " << bi << endl;
            bsz[bi]--; 
        } else {
            auto it = bbegin[pos/B];
            if (LOG) cout << pos/B << " " << *it << ende;
            advance(it, pos%B);
            cout << *it << ende;
        }
    }
    if (LOG) {
        for (auto it : l) cout << it << " ";
        cout << endl;
        for (auto it2 : bsz) cout << it2 << " ";
        cout << endl;
    }


    return 0;
}
