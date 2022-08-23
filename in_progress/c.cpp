#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

#define ende "\n"

// void push(int ti, int tl, int tm, int tr) {
//     { int sz = (tm - tl + 1);
//     t[ti*2] += lazy[ti] * FACTOR; }
//     lazy[ti*2] += lazy[ti];
//     { int sz = (tr - (tm+1) + 1);
//     t[ti*2+1] += lazy[ti] * FACTOR; }
//     lazy[ti*2+1] += lazy[ti];
//     lazy[ti] = 0;
// }

// void add_inclusive(int l, int r, int d,
//     int ti=1, int tl=1, int tr=N) {
//     if (l > r) { return; }
//     if (l == tl && tr == r) {
//         int sz = tr - tl + 1;
//         t[ti] += d * FACTOR; lazy[ti] += d; 
//         return; 
//     }
//     int tm = (tl + tr) / 2; push(ti, tl, tm, tr);

//     add_inclusive(l, min(r, tm), d, ti*2, tl, tm);
//     add_inclusive(max(l, tm+1), r, d, ti*2+1, tm+1, tr);
//     t[ti] = OP(t[ti*2], t[ti*2+1]);
// }

// ll op_inclusive(int l, int r,
//     int ti=1, int tl=1, int tr=N) {
//     if (l > r) { return NEUTRAL; }
//     if (l <= tl && tr <= r) { return t[ti]; }
//     int tm = (tl + tr) / 2; push(ti, tl, tm, tr);
//     return OP(op_inclusive(l, min(r, tm), ti*2, tl, tm),
//     op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr));
// }

// void build(vector<int>& src,
//     int ti=1, int tl=1, int tr=N) {
//     if (tl == tr) {
//         if (tl < src.size()) { t[ti] = src[tl]; }
//         return;
//     }
//     int tm = (tl + tr) / 2;
//     build(src, ti*2, tl, tm);
//     build(src, ti*2+1, tm+1, tr);
//     t[ti] = OP(t[ti*2], t[ti*2+1]);
// }

/*** ATRIBUIR ***/

vector<int> t (4*N); vector<bool> mark (4*N);

void push(int ti) {
    if (mark[ti]) {
        t[ti*2] = t[ti*2+1] = t[ti];
        mark[ti*2] = mark[ti*2+1] = true;
        mark[ti] = false;
    }
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

//ATRIB
int get(int i, int ti=1, int tl=1, int tr=N) {
    if (tl == tr) { return t[ti]; }
    push(ti); 
    int tm = (tl + tr) / 2;
    if (i <= tm) { return get(i, ti*2, tl, tm); }
    else { return get(i, ti*2+1, tm+1, tr); }
}

/*** ATRIBUIR ***/  

/*** ADIÇÃO ***/
vector<ll> t (4*N);
void add_inclusive(int l, int r, int d,
    int ti=1, int tl=1, int tr=N) {
    
    if (l > r) { return; }
    if (l == tl && r == tr) { t[ti] += d; return; }
    int tm = (tl + tr) / 2;
    add_inclusive(l, min(r, tm), d, ti*2, tl, tm);
    add_inclusive(max(l, tm+1), r, d, ti*2+1, tm+1, tr);
}

ll get(int i, int ti=1, int tl=1, int tr=N) {
    if (tl == tr) { return t[ti]; }
    int tm = (tl + tr) / 2;
    if (i <= tm) { return t[ti] + get(i, ti*2, tl, tm); }
    else { return t[ti] + get(i, ti*2+1, tm+1, tr); }
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

/*** ADIÇÃO ***/

int get(int i, int ti=1, int tl=1, int tr=N) {
    if (tl == tr) { return t[ti]; }
    push(ti); 
    int tm = (tl + tr) / 2;
    if (i <= tm) { return get(i, ti*2, tl, tm); }
    else { return t[ti] + get(i, ti*2+1, tm+1, tr); }
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
    
    

    return 0;
}
