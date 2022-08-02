/*** BEGIN BIG PRIME SIEVE***/

#define MAX_BIGPSIEVE 112345

int big[MAX_BIGPSIEVE + 1] = {1, 1};
void bigpsieve(){
    for (int i = 1; i*i <= MAX_BIGPSIEVE; ++i)
        if (big[i] == 1)
            for (int j = i; j <= MAX_BIGPSIEVE; j += i)
                big[j] = i;
}

/*** END BIG PRIME SIEVE ***/