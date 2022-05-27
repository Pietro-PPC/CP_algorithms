#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 300

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    char c;
    string buf;

    cin.get(c);
    getline(cin, buf);
    while (t--){
        vector<vector<string>> v(MAX);
        getline(cin, buf);
        while (buf.length() > 0){
            // cout << buf << " " << buf.length() << endl;
            v[buf.length()].PB(buf);
            getline(cin, buf);
        }
    }

    return 0;
}
