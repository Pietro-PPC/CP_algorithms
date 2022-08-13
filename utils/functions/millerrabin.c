/*** BEGIN MILLER-RABIN ***/

vector<int> witnesses = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool is_prime(ll n) {
	if (n < 2) { return false; }
	int s = __builtin_ctzll(n - 1);
	ll d = n >> s;
	for (int a : witnesses) {
		if (n == a) return true; 
		ll p = fast_pow(a, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = (i128)p * p % n;
		if (p != n - 1 && i != s) return false; 
	}
	return true;
}

/*** END MILLER-RABIN ***/