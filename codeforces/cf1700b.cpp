#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

#define MAX 112345

void subtract(int a[MAX], int b[MAX], int ans[MAX], int n){
    for (int i = 0; i < n; ++i){
        if (a[i] - b[i] < 0){
            a[i] += 10;
            a[i+1] -= 1;
        }
        ans[i] = a[i]-b[i];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string num; cin >> num;
        int intnum[MAX];
        for (int i = 0; i < n; ++i) intnum[n-1-i] = num[i] - '0';
        int subnum[MAX];

        for (int i = 0; i < n; ++i) 
            subnum[i]=9;
        if (num[0] == '9'){
            subnum[0]=1;
            subnum[1]=8;
            subnum[n-1]=8;
            subnum[n]=1;
        }

        
        int ans[MAX];
        subtract(subnum, intnum, ans, n);

        for (int i = n-1; i >= 0; --i)
            cout << ans[i];
        cout << ende;
    }

    return 0;
}
