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

struct inscrito{
    bool luta;
    bool hora;
    int xp, cl, ind;
};

bool cmp(inscrito ia, inscrito ib){
    if (ia.luta != ib.luta) return ia.luta;
    if (ia.hora != ib.hora) return ia.hora;
    if (ia.xp != ib.xp) return (ia.xp > ib.xp);
    return (ia.cl < ib.cl);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    inscrito a[MAX];
    int n, v; cin >> n >> v;
    for (int i = 0; i < n; ++i){
        string luta, hora;
        cin >> luta >> hora >> a[i].xp >> a[i].cl;
        a[i].luta = (luta == "idjassu" || luta == "galhofa" || luta == "aipenkuit");
        a[i].hora = ((hora[0]-'0' == 1 && hora[1]-'0' >= 3) || hora[0]-'0' > 1);
        a[i].ind = i+1;
    }
    sort(a, a+n, cmp);
    for (int i = 0; i < v; ++i)
        cout << a[i].ind << ende;

    return 0;
}
