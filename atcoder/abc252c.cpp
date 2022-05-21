#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char reels[MAX][11];
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> reels[i];
    }

    int occur[10]; 
    int ans = INT_MAX;
    for (int s = 0; s < 10; ++s){
        memset(occur, 0, sizeof(occur));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < 10; ++j){
                if (reels[i][j] - '0' == s)
                    (occur[j])++;
            }
        }
        int mai = 0;
        for (int i = 1; i < 10; ++i){
            if (occur[i] >= occur[mai])
                mai = i;
        }
        ans = min(ans, (occur[mai]-1) * 10 + mai);

    }    
    cout << ans << endl;

    return 0;
}
