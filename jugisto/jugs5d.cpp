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

#define MAX 112345

/***** BEGIN BIT *****/
#define MAX_BIT 112345
int N;

vector<int> bit (MAX_BIT, 0);
void add(int i, int delta) {
    for (; i <= N; i += i & (-i))
    bit[i] += delta;
}
int get(int i) {
    int ans = 0;
    for (; i > 0; i -= i & (-i))
    ans += bit[i];
    return ans;
}

/***** END BIT *****/


vector<int> fita_i(MAX, 0);

int dr(int a, int b){
    return ( get(b) - get(a-1) ) % 9;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    N = n;
    string fita_s;
    
    cin >> fita_s;
    for (int i = 0; i < fita_s.length(); ++i)
        add(i+1, (int)fita_s[i] - '0');

    int q; cin >> q;
    int o, a1, b1, a2, b2, d, p;
    while (q--){
        cin >> o;
        int cur_dr;
        if (o == 1){
            cin >> a1 >> b1 >> a2 >> b2 >> d;
            cur_dr = (dr(a1, b1) + dr(a2, b2)) % 9;
            cout << (cur_dr == d ? "YES" : "NO") << ende;
        }
        else if (o == 2){
            cin >> a1 >> b1 >> a2 >> b2 >> d;
            cur_dr = (dr(a1, b1) * dr(a2, b2)) % 9;
            cout << (cur_dr == d ? "YES" : "NO") << ende;
        }
        else{
            cin >> p >> d;
            int cur_val = get(p) - get(p-1);
            add(p, d - cur_val);
        }
    }


    return 0;
}
