#include <bits/stdc++.h>

using namespace std;

int main(){
    double r, d, c;
    cin >> r >> d >> c;
    
    double angle = 2*asin(d/(2*r));
    double arclen = r*angle;

    cout << (c >= 2*arclen? "possivel" : "impossivel") << endl;
}
