#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

struct cmp_str{
    bool operator()(const char *a, const char *b) const {
        return strcmp(a, b) < 0;
    }
};

struct medals{
    int gold, silver, bronze;
};

bool vector_order(pair<string, medals> const n1, pair<string, medals> const n2) {
    medals a = n1.second, b = n2.second;
    if (a.gold > b.gold) return true;
    else if (a.gold < b.gold) return false;
    else if (a.silver > b.silver) return true;
    else if (a.silver < b.silver) return false;
    else if (a.bronze > b.bronze) return true;
    else if (a.bronze < b.bronze) return false;
    else if (n1.first.compare(n2.first) < 0) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char c;
    map<string, medals> m;
    string buf;
    while (getline(cin, buf)){
        string fi, se, th;
        getline(cin, fi);
        getline(cin, se);
        getline(cin, th);
        if (m.find(fi) == m.end()){
            m[fi].gold = 1;
            m[fi].silver = 0;
            m[fi].bronze = 0;
        } 
        else m[fi].gold++;
        if (m.find(se) == m.end()){
            m[se].gold = 0;
            m[se].silver = 1;
            m[se].bronze = 0;
        } 
        else m[se].silver++;
        if (m.find(th) == m.end()){
            m[th].gold = 0;
            m[th].silver = 0;
            m[th].bronze = 1;
        } 
        else m[th].bronze++;
    }
    vector<pair<string, medals>> ans;
    for (auto &country : m){
        ans.PB(country);
    }
    sort(ans.begin(), ans.end(), vector_order);
    cout << "Quadro de Medalhas" << endl;
    for (auto &country : ans){
        cout << country.first << " " << country.second.gold << " " << country.second.silver << " " << country.second.bronze << endl;
    }


    return 0;
}
