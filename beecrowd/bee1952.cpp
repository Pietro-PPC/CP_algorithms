#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112


int dst[MAX][MAX][MAX];
int N, M, L;

int make_trio(int a, int b, int c){
    if (a<0) a = 999;
    if (b<0) b = 999;
    if (c<0) c = 999;
    return a*1000000 + b*1000 + c;
}

void get_trio(int n, int &a, int &b, int &c){
    a = n/1000000;
    b = (n/1000) % 1000;
    c = n % 1000;
}
bool valid(int n){
    int a, b, c;
    get_trio(n, a, b, c);
    return (a >= 0 && a < N && 
        b >= 0 && b < M && 
        c >= 0 && c < L);
}

int bfs(int t1, int t2){
    queue<pair<int, int>> Q;

    memset(dst, -1, sizeof(dst));
    int ret = -1;

    bool found = false;
    int a, b, c;
    get_trio(t1, a, b, c);

    Q.push({0, t1});
    while (!Q.empty()){
        auto[d, t] = Q.front(); Q.pop();
        int a, b, c;
        get_trio(t, a, b, c);

        if (!valid(t) || dst[a][b][c] != -1 || found) 
            continue;

        dst[a][b][c] = d;

        if (t == t2){
            found = true;
            ret = dst[a][b][c];
            continue;
        }


        for (int d1 = 2; d1 >= -2; d1--){
            int d2 = 3-abs(d1);
            if (d1){
                Q.push({d+1, make_trio(a+d1, b+d2, c)});
                Q.push({d+1, make_trio(a+d1, b-d2, c)});
                Q.push({d+1, make_trio(a, b+d1, c+d2)});
                Q.push({d+1, make_trio(a, b+d1, c-d2)});
                Q.push({d+1, make_trio(a+d2, b, c+d1)});
                Q.push({d+1, make_trio(a-d2, b, c+d1)});
            }
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int i1, i2, j1, j2, k1, k2;
    cin >> N >> M >> L;
    cin >> i1 >> j1 >> k1; i1--; j1--; k1--;
    cin >> i2 >> j2 >> k2; i2--; j2--; k2--;

    cout << bfs(make_trio(i1, j1, k1), make_trio(i2, j2, k2)) << endl;


    return 0;
}
