#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112

int _p[MAX], _rank[MAX];

void _make(int a){ _p[a] = a; _rank[a] = 1;}

int _find(int a){ return _p[a] == a ? a : (_p[a] = _find(_p[a]) );}

void _union(int a, int b){
    if (a == b) return;
    a = _find(a); b = _find(b);
    if (_rank[a] > _rank[b])
        _p[b] = a;
    else {
        if (_rank[a] == _rank[b]) _rank[b]++;
        _p[a] = b;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    for (int tt = 1; tt <= t; ++tt){
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) _make(i);
        for (int i = 0; i < m; ++i){
            int ra, rb; cin >> ra >> rb;
            _union(--ra, --rb);
        }
        set<int> s;
        for (int i = 0; i < n; ++i)
            s.insert(_find(i));
        int size = s.size();
        if (size == 1)
            cout << "Caso #" << tt << ": a promessa foi cumprida" << endl;
        else
            cout << "Caso #" << tt << ": ainda falta(m) " << size-1 << " estrada(s)" << endl;
    }

    return 0;
}
