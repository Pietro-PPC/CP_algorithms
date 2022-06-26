#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 112345

int indv[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
multiset<char> naipes[13];

int vet[15];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<char, int> mv;
    for (int i = 0; i < 13; ++i)
        mv[indv[i]] = i;
    memset(vet, 0, sizeof(vet));

    int n; cin >> n;
    vector<string> vs(MAX);
    for (int i = 0; i < n; ++i)
        cin >> vs[i];

    int ans = -1;
    for (int i = 0; i < 9 && ans == -1; ++i){
        char valin = vs[i][0];
        char naiin = vs[i][1];
        
        if (naipes[ mv[valin] ].find(naiin) == naipes[ mv[valin] ].end())
            vet[mv[valin]]++;
        naipes[ mv[valin] ].insert(naiin);

        if (vet[mv[valin]] == 3)
            ans = i+1;
    }

    for (int i = 9; i < n && ans == -1; ++i){
        char valin  = vs[i][0];
        char naiin  = vs[i][1];
        char valout = vs[i-9][0];
        char naiout = vs[i-9][1];

        naipes[mv[valout]].erase( naipes[mv[valout]].find(naiout) );
        if (naipes[mv[valout]].find(naiout) == naipes[mv[valout]].end())
            vet[mv[valout]]--;

        if (naipes[ mv[valin] ].find(naiin) == naipes[ mv[valin] ].end())
            vet[mv[valin]]++;
        naipes[ mv[valin] ].insert(naiin);

        if (vet[mv[valin]] == 3)
            ans = i+1;
    }
    cout << ans << ende;

    return 0;
}
