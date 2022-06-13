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
    
    int n; cin >> n;
    while (n){
        
        string name, ans;
        int a, t, minyear = 3000;

        for (int i = 0; i < n; ++i){
            cin >> name >> a >> t;
            if (a-t < minyear){
                minyear = a-t;
                ans = name;
            }
        }
        cout << ans << endl;

        cin >> n;
    }


    return 0;
}
