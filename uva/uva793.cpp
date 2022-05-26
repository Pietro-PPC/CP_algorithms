#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112345

int _p[MAX], _rank[MAX];

int _find(int a){ 
    return _p[a] == a ? a : (_p[a] = _find(_p[a]) );
}

void _make(int a){
    _p[a] = a; _rank[a] = 1;
}

void _union(int a, int b){
    a = _find(a);
    b = _find(b);
    if (_rank[a] > _rank[b])
        _p[b] = a;
    else {
        if (_rank[a] == _rank[b])
            _rank[b]++;
        _p[a] = b;    
    }
}

int main(){
    
    int t; scanf("%d\n", &t);
    while (t--){
        int n; scanf("%d", &n); getchar();
        for (int i = 1; i <= n; ++i) _make(i);
        int conn=0, n_conn=0;
        char c = getchar();
        while (c != '\n' && c != EOF){
            int a, b;
            scanf("%d %d", &a, &b); getchar();
            switch (c){
                case 'c':
                    _union(a,b);
                    break;
                case 'q':
                    if (_find(a) == _find(b))
                        conn++;
                    else
                        n_conn++;
                    break;
            }
            c = getchar();
        }
        printf("%d,%d\n", conn, n_conn);
        if (t) putchar(10);
    }

    return 0;
}
