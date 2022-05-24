#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

map<int,int> m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char c;
    int cnt = 0, flag = 0;
    while ((c = getchar()) != EOF){
        if ((c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z')) {
            flag = 0; 
            cnt++; 
        }
        else if (c == '-') flag = 1;
        else if (c == '\n' && flag) flag = 0;
        else if (c == '#'){
            for (auto it : m){
                cout << it.first << " " << it.second << endl;
            }
            cout << endl;
            m.clear();
        }
        else if (c != '\'' && cnt) {
            m[cnt]++;
            cnt = 0;
            flag = 0;
        }
    }

    return 0;
}
