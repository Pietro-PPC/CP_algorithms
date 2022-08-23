#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

#define ende "\n"

const int N = 8;

vector<int> t (4*N); vector<bool> mark (4*N);
void push(int ti) {
    if (mark[ti]) {
        t[ti*2] = t[ti*2+1] = t[ti];
        t[ti] = 0;
        mark[ti*2] = mark[ti*2+1] = true;
        mark[ti] = false;
    }
}

void push(int ti, int tl, int tm, int tr) {
    t[ti*2] += lazy[ti] * FACTOR; 
    lazy[ti*2] += lazy[ti];
    
    t[ti*2+1] += lazy[ti] * FACTOR; 
    lazy[ti*2+1] += lazy[ti];
    lazy[ti] = 0;
}

void add_inclusive(int l, int r, int d,
    int ti=1, int tl=1, int tr=N) {
    
    if (l > r) { return; }
    if (l == tl && r == tr) { t[ti] += d; return; }
    int tm = (tl + tr) / 2;
    add_inclusive(l, min(r, tm), d, ti*2, tl, tm);
    add_inclusive(max(l, tm+1), r, d, ti*2+1, tm+1, tr);
}

void set_inclusive(int l, int r, int v,
    int ti=1, int tl=1, int tr=N) {
    if (l > r) { return; }
    if (l == tl && tr == r) {
        t[ti] = v; mark[ti] = true; return; }
    push(ti); int tm = (tl + tr) / 2;
    set_inclusive(l, min(r, tm), v, ti*2, tl, tm);
    set_inclusive(max(l, tm+1), r, v, ti*2+1, tm+1, tr);
}


int get(int i, int ti=1, int tl=1, int tr=N) {
    if (tl == tr) { return t[ti]; }
    
    int ret = mark[ti] ? 0 : t[ti];
    push(ti); 
    int tm = (tl + tr) / 2;
    if (i <= tm) { return ret + get(i, ti*2, tl, tm); }
    else { return ret + get(i, ti*2+1, tm+1, tr); }
}

void build(vector<int>& src,
    int ti=1, int tl=1, int tr=N) {
    if (tl == tr) {
        if (tl < src.size()) { t[ti] = src[tl]; }
        return;
    }
    int tm = (tl+tr)/2;
    build(src, ti*2, tl, tm);
    build(src, ti*2+1, tm+1, tr);
    t[ti] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q; cin >> n >> q;
    vector<int> in(n+1);
    for (int i = 1; i <= n; ++i) cin >> in[i];
    build(in);

    for (int i = 0; i < q; ++i){
        int op, a, b; 
        cin >> op >> a >> b;
        if (op == 1){
            int x; cin >> x;
            add_inclusive(a, b, x);
        } else if (op == 2){
            int x; cin >> x;
            set_inclusive(a, b, x);
        } else {
            int ans = 0;
            while (a <= b)
                {ans += get(a); a++;}
            cout << ans << endl;
        }
    }

    return 0;
}
