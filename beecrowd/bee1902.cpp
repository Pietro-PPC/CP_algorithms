#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define LL_MAX 0x7fffffffffffffff

#define MP make_pair
#define PB push_back

#define MAX 112345

vector<string> pairs(MAX);
map<string, int> s2i;
int vis[MAX];

int dfs(int st, int i){
    if (vis[st]) return vis[st] == i;
        
    vis[st] = i;
    return dfs(s2i[pairs[st]], i);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char name1[11], name2[11];
    int n = 0;
    while (cin >> name1){
        cin >> name2;
        s2i[name1] = n;
        pairs[n++] = name2;
    }

    memset(vis, 0, sizeof(vis));
    int ans = 0;
    int i = 1;
    for (auto it : s2i){
        ans += dfs(it.second, i);
        i++;
    }
    cout << ans << endl;

    return 0;
}
