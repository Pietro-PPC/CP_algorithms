#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int max = -1;
    int k, n;
    vector<int> a(112), b(112);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] > max) max = a[i];
    }
    for (int i = 1; i <= k; ++i){
        cin >> b[i];
    }

    bool ans = false;
    for (int i = 1; i<= n; ++i){
        if (a[i] == max){
            for (int j = 1; j <= k; ++j)
                if (b[j] == i)
                    ans = true;
        }
    }

    cout << (ans ? "Yes\n" : "No\n");

    return 0;
}
