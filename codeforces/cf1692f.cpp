#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 212345

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[MAX];
        set<int> s;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
            s.insert(a[i]);
        }
        int l =0, r = 0;
        int curl = 0, curr = 0;
        for (int i = 1; i < n; ++i){
            if (a[i] == a[i-1]) curr++;
            else {
                if (curr - curl > r -l ) {
                    r = curr; l = curl;
                }
                curl = i; curr = i;
            }
        }
        cout << a[l] << " " << l << " " << r << ende;
    }

    return 0;
}
