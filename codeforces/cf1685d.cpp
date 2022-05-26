#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--){
        int a, b, ab, ba;
        string s; 
        cin >> a >> b >> ab >> ba;
        cin >> s;

        int alter = 1;
        int a_tot = 0, b_tot = 0;
        if (s[0] == 'A') a_tot++;
        else b_tot++;

        vector<int> a_even, b_even, odd;
        for (int i = 1; i < s.length(); ++i){
            if (s[i] == 'A') a_tot++;
            else b_tot++;

            if (s[i] != s[i-1]){
                alter++;
            } else {
                if (alter > 1){
                    if (alter & 1)
                        odd.push_back(alter);
                    else if (s[i-1] == 'A')
                        b_even.push_back(alter);
                    else
                        a_even.push_back(alter);
                }
                alter = 1;
            }
        }
        if (alter > 1){
            if (alter & 1)
                odd.push_back(alter);
            else if (s[s.length()-1] == 'A')
                b_even.push_back(alter);
            else
                a_even.push_back(alter);
        }
        
        sort(odd.begin(), odd.end());
        sort(a_even.begin(), a_even.end());
        sort(b_even.begin(), b_even.end());

        bool ans = true;

        if (a > a_tot - ab - ba)
            ans = false;
        else if (b > b_tot - ab - ba)
            ans = false;
        else {
            for (auto &len : a_even){
                while(ab > 0 && len > 1){
                    len -= 2;
                    ab--;
                }
            }
            for (auto &len : b_even){
                while(ba > 0 && len > 1){
                    len -= 2;
                    ba--;
                }
            }
            for (auto &len : odd){
                while (ab > 0 && len > 1){
                    len-=2;
                    ab--;
                }
            }
            for (auto &len : odd){
                while (ba > 0 && len > 1){
                    len-=2;
                    ba--;
                }
            }

            for (auto &len : b_even){
                if (len-2 > 1){
                    len -= 2;
                    while(ab > 0 && len > 1){
                        len -= 2;
                        ab--;
                    }
                }
            }
            for (auto &len : a_even){
                if (len-2 > 1){
                    len -= 2;
                    while(ba > 0 && len > 1){
                        len -= 2;
                        ba--;
                    }
                }
            }
            if (ab || ba) ans = false;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
