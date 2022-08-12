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
#define N_BIT 112345

vector<int> bit (N_BIT, 0);
void bit_add(int i, int delta) {
    for (; i < N_BIT; i += i & (-i))
    bit[i] += delta;
}
int bit_get(int i) {
    int ans = 0;
    for (; i > 0; i -= i & (-i))
    ans += bit[i];
    return ans;
}

/***** END BIT *****/

bool test_greater(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, h;
    cin >> n >> h;

    vector<int> p_ordem(MAX), p_sort(MAX);
    for(int i = 0; i < n; ++i){
        cin >> p_ordem[i];
        p_sort[i] = p_ordem[i];
    }
    
    sort(p_sort.begin(), p_sort.begin()+n, test_greater);
    map<int, int> p_map;
    for (int i = 0; i < n; ++i){
        p_map[p_sort[i]] = i+1;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i){
        if (i >= h){
            ans += bit_get(p_map[p_ordem[i]]);
        }
        bit_add(p_map[p_ordem[i]], 1);
    }
    cout << ans << endl;

    return 0;
}
