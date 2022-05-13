#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    double g = 0;
    int ans;
    int N; cin >> N;
    for (int i = 0; i < N; ++i){
        int D, C; cin >> D >> C;
        double cur = (double) C * abs(log((float) D));
        if (cur > g) {
            g = cur;
            ans = i;
        };
    }
    cout << ans << endl;

    return 0;
}
