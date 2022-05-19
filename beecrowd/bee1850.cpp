#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAX_LL 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112
#define KEY_COMBS 128

char L[MAX][MAX];
bool vis[KEY_COMBS][MAX][MAX];
pair<char,pii> prnt[KEY_COMBS][MAX][MAX];
int nlin, ncol;

bool iskey(char c){
    return c >= 'a' && c <= 'g';
}

bool isdoor(char c){
    return c >= 'A' && c <= 'G';
}

bool avail(char keys, int lin, int col){
    if (lin < 0 || lin >= nlin || col < 0 || col >= ncol)
        return false;

    char curPlace = L[lin][col];
    if (isdoor(curPlace) && !(keys & 1 << (curPlace - 'A')))
        return false;
    
    return !(vis[keys][lin][col]) && L[lin][col] != '#';
}

char bfs(pii st, pii en){
    queue<pair<char, pii>> Q;
    char endkeys = -1;

    memset(vis, false, sizeof(vis));
    memset(prnt, -1, sizeof(prnt));

    Q.push({0, st});
    vis[0][st.first][st.second] = true;
    while (!Q.empty()){
        auto [keys, P] = Q.front(); Q.pop();
        // cout << (int)keys << " " << P.first << " " << P.second << endl;
        char curCell = L[P.first][P.second];
        char initkeys = keys;

        if (iskey(curCell))
            keys = keys | (1 << (curCell - 'a'));
        if (curCell == '*' && endkeys == -1)
            endkeys = keys;
        if (endkeys != -1)
            continue;

        if (avail(keys, P.first, P.second-1)){
            Q.push({keys, {P.first, P.second-1}});
            // cout << 0 << " " << -1 << endl;
            prnt[keys][P.first][P.second-1].first = initkeys;
            prnt[keys][P.first][P.second-1].second = P;
            vis[keys][P.first][P.second-1] = true;
        }
        if (avail(keys, P.first, P.second+1)){
            Q.push({keys, {P.first, P.second+1}});
            // cout << 0 << " " << +1 << endl;
            prnt[keys][P.first][P.second+1].first = initkeys;
            prnt[keys][P.first][P.second+1].second = P;
            vis[keys][P.first][P.second+1] = true;
        }
        if (avail(keys, P.first-1, P.second)){
            Q.push({keys, {P.first-1, P.second}});
            // cout << -1 << " " << 0 << endl;
            prnt[keys][P.first-1][P.second].first = initkeys;
            prnt[keys][P.first-1][P.second].second = P;
            vis[keys][P.first-1][P.second] = true;
        }
        if (avail(keys, P.first+1, P.second)){
            Q.push({keys, {P.first+1, P.second}});
            // cout << +1 << " " << 0 << endl;
            prnt[keys][P.first+1][P.second].first = initkeys;
            prnt[keys][P.first+1][P.second].second = P;
            vis[keys][P.first+1][P.second] = true;
        }
    }

    return endkeys;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    pii st, en;
    nlin = 0;
    while (cin >> L[nlin++]){
        for (int i = 0; i < strlen(L[nlin-1]); ++i){
            if (L[nlin-1][i] == '*'){en.first = nlin-1; en.second = i;}
            if (L[nlin-1][i] == '@'){st.first = nlin-1; st.second = i;}
        }
    }
    nlin--;
    ncol = strlen(L[0]);
    char endkeys = bfs(st, en);

    if (endkeys == -1){
        cout << "--" << endl;
    }
    else {
        pair<char, pii> it = {endkeys, en};
        int ans = 0;
        while (it.first != 0 || it.second != st){
            // cout << (int)it.first << " " << it.second.first << " " << it.second.second << endl;
            char frst = prnt[it.first][it.second.first][it.second.second].first;
            pii secnd = prnt[it.first][it.second.first][it.second.second].second;
            it.first = frst;
            it.second = secnd;
            ans++;
        }
        // cout << (int)it.first << " " << it.second.first << " " << it.second.second << endl;
        cout << ans << endl;
    }
    return 0;
}
