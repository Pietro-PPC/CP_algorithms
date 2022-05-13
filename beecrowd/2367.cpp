#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define MAXN 1000123
#define MAXM 1123

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M; cin >> N >> M;
    int F[MAXN]; memset(F, 0, MAXN*sizeof(int));
    int P[MAXN]; memset(P, 0, MAXN*sizeof(int));

    for (int i = 0; i <= N; ++i){
        if (F[i] == 0){
            for (int j = 1; j <= M && i+j <= N; ++j){
                F[i+j]++;
                P[i+j] = j;
            }
        } else if (F[i] == 1){
            F[i + P[i]]++;
            P[i + P[i]] = P[i];
        }
    }
    
    if (F[N]) 
        cout << "Paula" << endl;
    else
        cout << "Carlos" << endl;

    return 0;
}
