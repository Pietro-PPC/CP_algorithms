#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string n1, n2;
    map<string, int> m;
    while (cin >> n1 >> n2){
        // cout << n1 << " " << n2 << endl;
        if (m.find(n1) != m.end()){
            if (m[n1] != -1 ) m[n1]++;
        } else {
            m[n1]++;
        }
        m[n2] = -1;
    }
    cout << "HALL OF MURDERERS" << endl;
    for (auto name : m)
        if (name.second > -1) cout << name.first << " " << name.second << endl;

    return 0;
}
