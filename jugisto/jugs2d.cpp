#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<string> s;
    int n, k;
    cin >> n >> k;
    int ans = true;
    for (int i = 0; i < 2*n; ++i){
        string cur;
        cin >> cur;
        if (s.find(cur) == s.end()){
            s.insert(cur);
            if ((int)s.size() >= k) ans = false;
        }
        else
            s.erase(cur);
    }
    cout << (ans ? "3.14159" : "7.18808") << ende;

    return 0;
}
