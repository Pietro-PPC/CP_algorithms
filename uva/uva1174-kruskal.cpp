#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 2123

int _p[MAX], _rank[MAX]; // MUF stuff

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

vector<piii> eg;
int kruskal(){
    sort(eg.begin(), eg.end());
    int ans = 0;
    for (auto &[w, edge] : eg){
        int u, v;
        tie(u, v) = edge;
        if (_find(u) != _find(v)){
            _union(u, v);
            ans += w;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    scanf("%d\n", &t);
    map<string, int> s2u;    

    while (t--){
        int m, n, wei, cnt = 0;
        char c1[10], c2[10];

        scanf("%d %d", &m, &n);
        for (int i = 0; i < n; ++i){
            scanf("%s %s %d", c1, c2, &wei);
            string sc1(c1), sc2(c2);
            if (s2u.find(sc1) == s2u.end()) {
                _make(cnt);
                s2u[sc1] = cnt++;
            }
            if (s2u.find(sc2) == s2u.end()) {
                _make(cnt);
                s2u[sc2] = cnt++;
            }
            eg.PB( piii(wei, pii(s2u[sc1], s2u[sc2])) );
        }
        printf("%d\n%s", kruskal(), t ? "\n" : "");
        s2u.clear();
        eg.clear();
    }

    return 0;
}
