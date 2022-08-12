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
    
    int n; cin >> n;
    stack<int> st;
    bool ans = true;
    while (n--){
        int a; char d;
        cin >> a >> d;
        if (d == 'L'){
            if (!st.empty() && st.top() <= a)
                {ans = false; n = 0;}
            else st.push(a);
        } else {
            if (st.empty() || st.top() != a)
                {ans = false; n = 0;}
            else st.pop();
        }
    }
    cout << (ans ? "S" : "N") << ende;

    return 0;
}
