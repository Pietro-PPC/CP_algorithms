#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_INF 0x7f7f7f7f7f7f7f7f
#define INT_INF 0x7f7f7f7f
#define ende "\n"

#define MP make_pair
#define PB push_back

/**** BEGIN SEGTREE *****/

#define OP(X, Y) ((X) * (Y)) // Define operation 
#define NEUTRAL 1 // Neutral element of operation   
#define MAX 112345 // Max segtree size

int N;
vector<int> t(2*MAX);
void st_build(std::vector<int> &src){
    for (int i = 0; i < src.size(); ++i)
        t[N+i] = src[i];
    for (int i = N-1; i > 0; --i)
        t[i] = OP(t[2*i], t[2*i+1]);
}

void st_set(int i, int v){
    t[i += N] = v;
    for (i /= 2; i > 0; i /= 2)
        t[i] = OP(t[i*2], t[i*2+1]);
}

int st_op(int l, int r){
    r++;
    int left = NEUTRAL, right = NEUTRAL;
    for (l += N, r += N; l < r; l /= 2, r /= 2){
        if (l & 1) left = OP(left, t[l++]);
        if (r & 1) right = OP(right, t[--r]);
    }
    return OP(left, right);
}

/***** END SEGTREE *****/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    vector<int> src(MAX);
    
    cin >> n >> k;
    N = n;
    for (int i = 1; i < n; ++i){
        cin >> src[i];
        if (src[i] > 0) src[i] = 1;
        else if (src[i] < 0) src[i] = -1;
    }
    
    st_build(src);
    for (int i = 0; i < k; ++i){
        char op; cin >> op;
        int a, b; cin >> a >> b;

        // cout << op << " " << a << " " << b << endl;
        if (op == 'A'){
            if (b > 0) b = 1;
            else if (b < 0) b = -1;
            a--;

            st_set(a, b);
        }
        else{
            a--; b--;

            int rmul = st_op(a, b);
            if (rmul < 0) cout << '-';
            else if (rmul > 0) cout << '+';
            else cout << 0;
        }
    }
    cout << ende;    

    return 0;
}
