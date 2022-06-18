#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 15

bool forb[MAX][MAX];
int n, c; 
int seq[MAX], used[MAX];

void gen(int k){
    if (k == n){
        for (int i = 0; i < n; ++i)
            cout << seq[i] << " ";
        cout << ende;
    }
    for (int i = 1; i <= n; ++i) if (!used[i]){
        used[i] = 1; seq[k] = i;
        int ok = 1;
        for (int j = 0; j < k && ok; ++j)
            if (forb[seq[j]][i]) ok = 0;
        if (ok) gen(k+1);
        used[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c;
    memset(forb, 0, sizeof(forb));
    for (int i = 0; i < c; ++i){
        int a, b; cin >> a >> b;
        forb[b][a] = true;
    }

    memset(used, 0, sizeof(used));
    gen(0);

    return 0;
}
