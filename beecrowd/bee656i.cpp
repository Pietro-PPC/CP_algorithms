#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

double hip(double a, double b){
    return sqrt(a*a+b*b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    double n, h, c, l;
    while(cin >> n){
        cin >> h >> c >> l;
        h/=100;
        c/=100;
        l/=100;
        double len = n*hip(h, c);

        cout << fixed << setprecision(4) << len*l << endl;
    }

    return 0;
}
