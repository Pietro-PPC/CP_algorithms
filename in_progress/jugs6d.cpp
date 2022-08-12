#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define ende "\n"

#define INF 112345
#define MAX 412

int g[MAX][MAX], dp[MAX][MAX];
int dist[MAX][MAX];
int n, m; 
map<string, int> s2i;
vector<string> itos(MAX);

void floyd_warshall(){
    for (int u = 0; u < n; ++u)
        dist[u][u] = 0;
    
    for (int k = 0; k < n; ++k)
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v){
                int withk = dist[u][k] + dist[k][v];
                if (withk < dist[u][v]){
                    dist[u][v] = withk;
                    dp[u][v] = k;
                }
            }
}

void bfs (tuple<int, string, string> &med, vector<int> &path){
    string s1 = get<1>(med), s2 = get<2>(med);
    int i1 = s2i[s1], i2 = s2i[s2];

    vector<int> prnt(MAX, -1);
    queue<int> q;
    q.push(i1);
    while (!q.empty()){
        int u = q.front(); q.pop();
        for(int v = 0; v < n; ++v){
            if (dist[u][v] == 1 && prnt[v] == -1){
                q.push(v);
                prnt[v] = u;
            }
        }
    }

    int size = dist[i1][i2];
    cout << itos[i1] << " " << itos[i2] << endl;
    for (int u = i2; u != i1; u = prnt[u]){
        cout << u << " " << itos[u] << endl;
        path[size--] = u;
    }
    path[0] = i1;
}

// void reconstruct_path(tuple<int, string, string> &med, vector<int> &path, int off){
//     string s1 = get<1>(med), s2 = get<2>(med);
//     int i1 = s2i[s1], i2 = s2i[s2];
//     if (i1 == i2){
//         path[off] = i1;
//         return;
//     }
    
//     int im = dp[i1][i2];
    
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dist[i][j] = INF;
    
    int cur_ind = 0;
    for (int i = 0; i < m; ++i){
        string a, b;
        cin >> a >> b;
        if (s2i.find(a) == s2i.end()) {
            s2i[a] = cur_ind;
            itos[cur_ind++] = a;
        }
        if (s2i.find(b) == s2i.end()) {
            s2i[b] = cur_ind;
            itos[cur_ind++] = b;
        }
        dist[s2i[a]][s2i[b]] = dist[s2i[b]][s2i[a]] = 1;
    }
    
    floyd_warshall();

    vector< tuple<int, string, string> > egs;
    double avg = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j){
            avg += dist[i][j];
            cout << i << " " << j << endl;
            // if (itos[j] < itos[i])
                // egs.push_back(make_tuple(dist[j][i], itos[j], itos[i]));
            // else
                egs.push_back(make_tuple(dist[i][j], itos[i], itos[j]));
        }

    cout << "size egs " << egs.size() << endl;
    avg /= egs.size(); // media
    sort(egs.begin(), egs.end());

    tuple <int, string, string> med = egs[egs.size()/2 - 1]; // mediana
    int ind_ini = s2i[ get<1>(med) ];
    int ind_fim = s2i[ get<2>(med) ];

    vector<int> path(n);
    bfs(med, path);

    cout << fixed << setprecision(5) << avg << endl;
    cout << ind_ini << ' ' << ind_fim << endl;
    for (int i = 0; i <= dist[ind_ini][ind_fim]; ++i)
        cout << itos[ path[i] ] << " ";
    cout << ende;

    return 0;
}
