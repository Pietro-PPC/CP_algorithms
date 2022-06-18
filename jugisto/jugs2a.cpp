#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define LL_MAX 0x7fffffffffffffff
#define ende "\n"

#define MP make_pair
#define PB push_back

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bool isfifo = true, islifo = true, isprio = true;
    priority_queue<int> pq;
    queue<int> q;
    stack<int> st;
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int op, id;
        cin >> op >> id;
        if (!op){
            pq.push(id);
            st.push(id);
            q.push(id);
        } else {
            int cpq, cq, cst;
            cpq = pq.top(); pq.pop();
            cq = q.front(); q.pop();
            cst = st.top(); st.pop();
            if (cpq != id) isprio = false;
            if (cq != id) isfifo = false;
            if (cst != id) islifo = false;
        }
    }
    if (isprio && !isfifo && !islifo)
        cout << "priority" << ende;
    else if (!isprio && isfifo && !islifo)
        cout << "fifo" << ende;
    else if (!isprio && !isfifo && islifo)
        cout << "lifo" << ende;
    else if (!isprio && !isfifo && !islifo)
        cout << "unknown" << ende;
    else 
        cout << "ambiguous" << ende;

    return 0;
}
