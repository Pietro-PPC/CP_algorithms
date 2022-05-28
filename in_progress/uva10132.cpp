#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 300

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; 
    char c;
    string buf;
    map<string, bool> m;
    
    cin >> t; cin.get(c);
    getline(cin, buf);
    while (t--){
        int min, max;
        int cntini[2], cntfim[2];
        vector<vector<string>> v(MAX);

        getline(cin, buf);
        memset(cntini, 0, sizeof(cntini));
        memset(cntfim, 0, sizeof(cntfim));
        min = max = buf.length();
        while (buf.length() > 0){
            if (m.find(buf) == m.end()){
                v[buf.length()].PB(buf);
                cntini[buf[0]]++;
                cntfim[buf[buf.length()-1]]++;
                m[buf] = 1;
            }
            if (buf.length() < min) min = buf.length();
            if (buf.length() > max) max = buf.length();
            getline(cin, buf);
        }
        
        int startswith = -1, endswith = -1;
        if (cntini[0] > cntini[1]) startswith = 0;
        else if (cntini[0] < cntini[1]) startswith = 1;
        if (cntfim[0] > cntfim[1]) endswith = 0;
        else if (cntfim[0] < cntfim[1]) endswith = 1;

        int mid = (min+max)/2;
        int str_size = min+max;
        vector<string> answers;
        for (int i = min; i <= mid; ++i){
            cout << i << endl;
            switch (v[i].size()){
                case 1:
                    answers.PB(v[i][0] + v[max-i][0]);
                    answers.PB(v[max-i][0] + v[i][0]);
                case 2: 
                    answers.PB(v[i][0] + v[max-i][1]);
                    answers.PB(v[i][1] + v[max-i][0]);
                    answers.PB(v[i][1] + v[max-i][1]);
                    answers.PB(v[max-i][0] + v[i][1]);
                    answers.PB(v[max-i][1] + v[i][0]);
                    answers.PB(v[max-i][1] + v[i][1]);
                break;
            }

        }
    }

    return 0;
}
