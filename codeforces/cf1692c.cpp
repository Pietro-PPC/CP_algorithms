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
    
    char board[8][10];
    int t; cin >> t;
    while (t--){
        for (int i = 0; i < 8; ++i)
            cin >> board[i];
        
        int bis[8];
        for (int i = 0; i < 8; ++i){
            int cnt = 0;
            for (int j = 0; j < 8; ++j)
                if (board[i][j] == '#') cnt++;
            bis[i] = cnt;
        }
        int r = 0;
        while (bis[r] < 2) ++r;
        while (bis[r] != 1) ++r;
        
        int c = 0;
        while (board[r][c] != '#') c++;
        cout << r+1 << " " << c+1 << ende;

    }

    return 0;
}
