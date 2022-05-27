#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 212345

int _p[MAX], _rank[MAX];
int people[MAX];

void _make(int a){ _p[a] = a; _rank[a] = 1; people[a] = 1;}

int _find(int a){ return _p[a] == a ? a : (_p[a] = _find(_p[a]) );}

void _union(int a, int b){
    if (a == b) return;
    a = _find(a); b = _find(b);
    

    if (_rank[a] > _rank[b]){
        _p[b] = a;
        if (a != b) people[a] = people[a] + people[b];
    }

    else {
        if (_rank[a] == _rank[b]) _rank[b]++;
        _p[a] = b;
        if (a != b) people[b] = people[a] + people[b];
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int f; cin >> f;
        string n1, n2;
        int cnt = 0;
        map<string, int> ind;
        for (int i = 0; i < f; ++i){
            cin >> n1 >> n2;
            if (ind.find(n1) == ind.end()){
                ind[n1] = cnt;
                _make(cnt++);
            }
            if (ind.find(n2) == ind.end()){
                ind[n2] = cnt;
                _make(cnt++);
            }
            _union(ind[n1], ind[n2]);
            cout << people[_find(ind[n1])] << endl;
        }
    }

    return 0;
}
