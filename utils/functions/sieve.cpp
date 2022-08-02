/*** BEGIN SIEVE***/

#define MAX_SIEVE 112345
vector<bool> isprime(MAX_SIEVE+1, true);
vector<ll> primes;

void sieve(){
    for (ll i = 2; i*i <= MAX_SIEVE; ++i) if (isprime[i])
        for (ll j = i*i; j <= MAX_SIEVE; j += i)
            isprime[j] = false;

    for (ll i = 2; i <= MAX_SIEVE; ++i) if (isprime[i])
        primes.push_back(i);
}

/*** END SIEVE ***/