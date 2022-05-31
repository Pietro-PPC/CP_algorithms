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
    
    int t; 
    char c;
    string buf;
    map<string, bool> m;
    
    cin >> t; cin.get(c);
    getline(cin, buf);
    while (t--){
        unsigned int min, max;
        vector<vector<string>> v(MAX);
        getline(cin, buf);
        min = max = buf.length();
        while (buf.length() > 0){
            v[buf.length()].PB(buf);
            if (buf.length() < min) min = buf.length();
            if (buf.length() > max) max = buf.length();
            getline(cin, buf);
        }
        map<string,unsigned int> ans;
        
        int mid = (min+max)/2;
        int str_size = min+max;
        set<string> curans;
        for (int i = min; i <= mid; ++i){
            int comp = str_size - i;
            for (auto &iti : v[i]){
                for (auto &itcomp : v[comp]){
                    curans.insert(iti+itcomp);
                    curans.insert(itcomp+iti);
                }
            }
            for (auto &cur : curans)
                ans[cur]++;
            curans.clear();
        }
        for (auto &aa : ans){
            if (aa.second == (mid-min+1)){
                cout << aa.first << endl;
                break;
            }
        }
        if (t) cout << endl;
    }

    return 0;
}
