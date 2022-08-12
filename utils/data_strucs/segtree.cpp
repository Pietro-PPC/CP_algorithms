/**** BEGIN SEGTREE *****/

#define OP(X, Y) ((X) + (Y)) // Define operation 
#define NEUTRAL 0 // Neutral element of operation   
#define N 11234 // Max segtree size

vector<int> t(2*N);
void st_build(std::vector<int> &src){
    for (int i = 0; i < src.size(); ++i)
        t[N+i] = src[i];
    for (int i = N-1; i > 0; --i)
        t[i] = OP(t[2*i], t[2*i+1]);
}

void st_set(int i, int v){
    t[i += N] = v;
    for (i /= 2; i > 0; i /= 2)
        t[i] = OP(t[i*2], t[i*2+1]);
}

int st_op(int l, int r){
    r++;
    int left = NEUTRAL, right = NEUTRAL;
    for (l += N, r += N; l < r; l /= 2, r /= 2){
        if (l & 1) left = OP(left, t[l++]);
        if (r & 1) right = OP(right, t[--r]);
    }
    return OP(left, right);
}

/***** END SEGTREE *****/