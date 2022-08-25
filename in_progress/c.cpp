#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

#define ende "\n"

#define FACTOR sz
#define OP(X, Y) (X + Y)
#define NEUTRAL 0

const int N = 2e5 + 15;
// const int N = 8;

vector<ll> t (4*N); vector<ll> lazy (4*N); vector<bool> mark (4*N, false);

void push(int ti, int tl, int tm, int tr) {
    { 
        int sz = (tm - tl + 1);
        if (mark[ti]){
            t[ti*2] = t[ti];
            mark[ti*2] = true;
        }
        t[ti*2] += lazy[ti] * FACTOR; 
    }
    lazy[ti*2] += lazy[ti];

    { 
        int sz = (tr - (tm+1) + 1);
        if (mark[ti]){
            t[ti*2+1] = t[ti];
            mark[ti*2+1] = true;
        }
        t[ti*2+1] += lazy[ti] * FACTOR; 
    }
    lazy[ti*2+1] += lazy[ti];

    mark[ti] = false;
    lazy[ti] = 0;
}

void add_inclusive(int l, int r, int d,
    int ti=1, int tl=1, int tr=N) {
    
    if (l > r) { return; }
    if (l == tl && tr == r) {
        int sz = tr - tl + 1;
        t[ti] += d * FACTOR; lazy[ti] += d; return; 
    }

    int tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    add_inclusive(l, min(r, tm), d, ti*2, tl, tm);
    add_inclusive(max(l, tm+1), r, d, ti*2+1, tm+1, tr);
    t[ti] = OP(t[ti*2], t[ti*2+1]);
}

void set_inclusive(int l, int r, int v,
    int ti=1, int tl=1, int tr=N) {
    // return;

    if (l > r) { return; }
    // if (l == tl && tr == r) {
    //     t[ti] = v; mark[ti] = true; return; }
    if (l == tl && tr == r) {
        int sz = tr - tl + 1;
        t[ti] = v * FACTOR;
        lazy[ti] = 0; 
        mark[ti] = true;
        return; 
    }
    int tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    set_inclusive(l, min(r, tm), v, ti*2, tl, tm);
    set_inclusive(max(l, tm+1), r, v, ti*2+1, tm+1, tr);
}

ll op_inclusive(int l, int r,
    int ti=1, int tl=1, int tr=N) {

    if (l > r) { return NEUTRAL; }
    if (l <= tl && tr <= r) { return t[ti]; }
    int tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    return OP(op_inclusive(l, min(r, tm), ti*2, tl, tm),
        op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr));
}

void build(vector<int>& src,
    int ti=1, int tl=1, int tr=N) {
    if (tl == tr) {
        if (tl < src.size()) { t[ti] = src[tl]; }
        return;
    }
    int tm = (tl + tr) / 2;
    build(src, ti*2, tl, tm);
    build(src, ti*2+1, tm+1, tr);
    t[ti] = OP(t[ti*2], t[ti*2+1]);
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
            cout << op_inclusive(a, b) << endl;
        }
    }

    // for (auto el : t){
    //     cout << el << " ";
    // }
    // cout << ende;

    return 0;
}
