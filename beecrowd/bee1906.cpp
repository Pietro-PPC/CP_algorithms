#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 11234567
#define MAXN 10000000

int dst[MAX];
int n, k;

void bfs(int st){
    queue<int> q;

    if (st == 1)
        dst[st] = k-1;
    else
        dst[st] = 0;
    q.push(st);
    while (!q.empty()){
        int cur = q.front(); q.pop();
        if (cur*2 <= n){
            q.push(cur*2);
            dst[cur*2] = dst[cur]+1;
        }
        int cand = (cur-1)/3;
        if (cur%3 == 1 && cand & 1 && cur > 4 ) {
            q.push(cand);
            dst[cand] = dst[cur]+1;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if (n < 4){
        if (k == 1)
            cout << n << endl;
        else if (k == 2 && n > 1)
            cout << 1 << endl;
        else 
            cout << 0 << endl;
        return 0;
    }


    memset(dst, -1, sizeof(dst));
    for (int i = 1; i <= n; ++i){
        if (dst[i] == -1)
            bfs(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (dst[i] >= k-1) ans++;
    }

    cout << ans << endl;
    return 0;
}
