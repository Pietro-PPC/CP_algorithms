/***** START MUF *****/

int _p[], _rank[];

void _make(int a){ _p[a] = a; _rank[a] = 1;}

int _find(int a){ return _p[a] == a ? a : (_p[a] = _find(_p[a]) );}

void _union(int a, int b){
    if (a == b) return;
    a = _find(a); b = _find(b);
    if (_rank[a] > _rank[b])
        _p[b] = a;
    else {
        if (_rank[a] == _rank[b]) _rank[b]++;
        _p[a] = b;
    }
}

/***** END MUF *****/