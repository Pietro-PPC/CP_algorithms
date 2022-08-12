#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7f7f7f7f7f7f7f7f
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 212345

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    vector<char> auxa, auxb;
    vector<int> qta, qtb;
    cin >> a >> b;
    int i = 0;
    while(i < a.length()){
        int cnt = 1;
        auxa.push_back(a[i]);
        while (a[i] == a[i+1] && i < a.length()) {++i; ++cnt;}
        qta.push_back(cnt);
        ++i;
    }
    i = 0;
    while(i < b.length()){
        int cnt = 1;
        auxb.push_back(b[i]);
        while (b[i] == b[i+1] && i < b.length()) {++i; ++cnt;}
        qtb.push_back(cnt);
        ++i;
    }
    int ok = 1;
    if (auxa.size() != auxb.size())
        ok = 0;
    else 
        for (int i = 0; i < auxa.size(); ++i)
            if (auxa[i] != auxb[i]) ok = 0;
            else if (qta[i] == 1 && qtb[i] > 1) ok = 0;
            else if (qta[i] > qtb[i]) ok = 0;

    cout << (ok ? "Yes" : "No") << ende;

    return 0;
}
