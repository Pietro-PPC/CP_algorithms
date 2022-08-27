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

const ll N = 2e5 + 15;
// const int N = 8;

vector<ll> t (4*N); 
vector<ll> lazyInc (4*N, 0);
vector<ll> lazySet (4*N); 
vector<bool> mark (4*N, false);

void push(ll ti, ll tl, ll tm, ll tr) {
    { 
        ll sz = (tm - tl + 1);
        if (mark[ti]){
            t[ti*2] = lazySet[ti] * FACTOR;
            lazyInc[ti*2] = lazyInc[ti];
            lazySet[ti*2] = lazySet[ti];
            mark[ti*2] = true;
        }
        else lazyInc[ti*2] += lazyInc[ti];
        t[ti*2] += lazyInc[ti] * FACTOR; 
    }

    { 
        ll sz = (tr - (tm+1) + 1);
        if (mark[ti]){
            t[ti*2+1] = lazySet[ti] * FACTOR;
            lazyInc[ti*2+1] = lazyInc[ti];
            lazySet[ti*2+1] = lazySet[ti];
            mark[ti*2+1] = true;
        }
        else lazyInc[ti*2+1] += lazyInc[ti];
        t[ti*2+1] += lazyInc[ti] * FACTOR; 
    }

    mark[ti] = false;
    lazyInc[ti] = 0;
}

void add_inclusive(ll l, ll r, ll d,
    ll ti=1, ll tl=1, ll tr=N) {
    
    if (l > r) { return; }
    if (l == tl && tr == r) {
        ll sz = tr - tl + 1;
        t[ti] += d * FACTOR; lazyInc[ti] += d; return; 
    }

    ll tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    add_inclusive(l, min(r, tm), d, ti*2, tl, tm);
    add_inclusive(max(l, tm+1), r, d, ti*2+1, tm+1, tr);
    t[ti] = OP(t[ti*2], t[ti*2+1]);
}

void set_inclusive(ll l, ll r, ll v,
    ll ti=1, ll tl=1, ll tr=N) {
    // return;

    if (l > r) { return; }
    // if (l == tl && tr == r) {
    //     t[ti] = v; mark[ti] = true; return; }
    if (l == tl && tr == r) {
        ll sz = tr - tl + 1;
        t[ti] = v * FACTOR;
        lazySet[ti] = v; lazyInc[ti] = 0;
        mark[ti] = true;
        return; 
    }
    ll tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    set_inclusive(l, min(r, tm), v, ti*2, tl, tm);
    set_inclusive(max(l, tm+1), r, v, ti*2+1, tm+1, tr);
    t[ti] = OP(t[ti*2], t[ti*2+1]);
}

ll op_inclusive(ll l, ll r,
    ll ti=1, ll tl=1, ll tr=N) {

    if (l > r) { return NEUTRAL; }
    if (l <= tl && tr <= r) { return t[ti]; }
    ll tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    return OP(op_inclusive(l, min(r, tm), ti*2, tl, tm),
        op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr));
}

void build(vector<ll>& src,
    ll ti=1, ll tl=1, ll tr=N) {
    if (tl == tr) {
        if (tl < src.size()) { t[ti] = src[tl]; }
        return;
    }
    ll tm = (tl + tr) / 2;
    build(src, ti*2, tl, tm);
    build(src, ti*2+1, tm+1, tr);
    t[ti] = OP(t[ti*2], t[ti*2+1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, q; cin >> n >> q;
    vector<ll> in(n+1);
    for (ll i = 1; i <= n; ++i) cin >> in[i];
    build(in);

    for (ll i = 0; i < q; ++i){
        ll op, a, b; 
        cin >> op >> a >> b;
        if (op == 1){
            ll x; cin >> x;
            add_inclusive(a, b, x);
        } else if (op == 2){
            ll x; cin >> x;
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
