#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7f7f7f7f7f7f7f7f
#define ende "\n"

#define MP make_pair
#define PB push_back

const double pi = 2*acos(0.0);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    double a, b, d;
    cin >> a >> b >> d;
    double theta = (d*pi)/180;
    double aprim = cos(theta)*a - sin(theta)*b;
    double bprim = sin(theta)*a + cos(theta)*b;
    cout << fixed << setprecision(10) << aprim << " " << bprim << ende;

    return 0;
}
