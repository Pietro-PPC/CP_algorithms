#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

int ispalin[2123];
void build(){
    memset(ispalin, 0, sizeof(ispalin));
    for (int h = 0; h < 6; ++h){
        int m = 10*h;
        ispalin[h*60+m] = 1;
    }
    ispalin[10*60+1] = 1;
    ispalin[11*60+11] = 1;
    ispalin[12*60+21] = 1;
    ispalin[13*60+31] = 1;
    ispalin[14*60+41] = 1;
    ispalin[15*60+51] = 1;
    
    ispalin[20*60+2] = 1;
    ispalin[21*60+12] = 1;
    ispalin[22*60+22] = 1;
    ispalin[23*60+32] = 1;

}

int next(int cur, int x){
    return (cur + x) % 1440;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; scanf("%d", &t);
    build();
    while (t--){
        int h, m, x;
        scanf("%d:%d %d", &h, &m, &x);
        int first = h*60+m;
        int ans = 0;
        if (ispalin[first]) ans++;
        for (int it = next(first, x); it != first; it = next(it, x)){
            if (ispalin[it]) ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
