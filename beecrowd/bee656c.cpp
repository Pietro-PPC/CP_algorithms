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
    
    string s; cin >> s;
    stack<char> st;
    for (uint i = 0; i < s.size(); ++i){
        if (i%2) cout << s[i];
        else st.push(s[i]);
    }
    while (!st.empty()){
        cout << st.top(); st.pop();
    }
    cout << endl;

    return 0;
}
