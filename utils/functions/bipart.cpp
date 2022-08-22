/*** BEGIN BIPART ***/
vector<int> g_t[MAX];
map<int, int> m_l, m_r;
void build_g(int &l, int &r){
    queue<pii> q;

    vector<bool> visbg(MAX, false);
    q.push({0, 0});
    visbg[0] = true;
    while (!q.empty()){
        auto [u, lvl] = q.front(); q.pop();

        for (auto v : g_t[u]){
            // cout << v << ende;
            if (!visbg[v]){

                q.push({v, lvl+1});
                visbg[v] = true;
                if (lvl%2) 
                    { m_l[v] = l++;  //cout << v << " = l " << l-1 << endl;
                    g[ m_l[v] ].push_back(m_r[u]); }
                
                else 
                    { m_r[v] = r++;  //cout << v << " = r " << r-1 << endl;
                    g[ m_l[u] ].push_back(m_r[v]); }
            }
        }

    }
}
/*** END BIPART ***/