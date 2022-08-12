/***** BEGIN BIT *****/
#define N_BIT 112345

vector<int> bit (N_BIT, 0);
void bit_add(int i, int delta) {
    for (; i < N_BIT; i += i & (-i))
    bit[i] += delta;
}
int bit_get(int i) {
    int ans = 0;
    for (; i > 0; i -= i & (-i))
    ans += bit[i];
    return ans;
}

/***** END BIT *****/
