/* ***** BEGIN BIT ***** */

vector<int> bit (N, 0);
void add(int i, int delta) {
    for (; i < N; i += i & (-i))
    bit[i] += delta;
}
int get(int i) {
    int ans = 0;
    for (; i > 0; i -= i & (-i))
    ans += bit[i];
    return ans;
}

/* ***** END BIT ***** */
