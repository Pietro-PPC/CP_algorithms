#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7f7f7f7f7f7f7f7f
#define ende "\n"

#define MP make_pair
#define PB push_back

#define N 112345
int n, q, t[N];

/* ***** BEGIN BIT ***** */
vector<int> bit (N, 0);
void add(int i, int delta) {
    for (; i < N; i += i & (-i))
    bit[i] += delta;
}
int get(int i) {
    int ans = 0;
    for (; i > 0; i -= i & (-i))
    ans += bit[i];
    return ans;
}

/* ***** END BIT ***** */

int search_idx(int key){
    int lo = 1;
    int hi = N;

    while (lo < hi){
        int mid = lo + (hi-lo)/2;
        if (get(mid) < key) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        add(i, 1);
        cin >> t[i];
    }
    
    int it = 1, num_elems = n;
    for (int i = 0; i < q; ++i){
        char op; cin >> op;
        int cur_it;
        switch(op){
            case 'd':
                cur_it = get(it);
                add(it, -1);
                if (cur_it == num_elems) cur_it--;
                it = search_idx(cur_it);
                num_elems--;
                break;
            case 'm':
                int d; cin >> d;
                cur_it = get(it);
                it = search_idx(cur_it + d);
                break;
            case 'q':
                cout << t[it] << ende;
                break;
        }
        // cout << ende << it << ende;
        // for (int i = 1; i <= n; ++i)
        //     cout << get(i) << " ";
        // cout << ende;
    }

    return 0;
}
