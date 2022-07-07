#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

string remove_dots(string s){
    string ans;
    for (auto &it : s)
        if (it != '.')
            ans += it;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    set<string> st;
    while (t--){
        string s; cin >> s;
        string usr = remove_dots(s.substr(0, s.find("@")).substr(0, s.find("+")));
        s.erase(0, s.find("@")+1);
        string prov = s;
        st.insert(usr+" "+prov);
    }
    cout << st.size() << ende;

    return 0;
}
