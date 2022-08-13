
/*** BEGIN MILLER-RABIN ***/

ll fast_pow128(ll a, ll e, ll m) {
	if (e == 0) { return 1; }
	if (e == 1) { return a; }
	ll res = fast_pow128(a, e/2, m);
	res = (i128)res * res % m;
	if (e % 2) res = (i128)res * a % m;
	return res;
}

vector<int> witnesses = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool is_prime(ll n) {
	if (n < 2) { return false; }
	int s = __builtin_ctzll(n - 1);
	ll d = n >> s;
	for (int a : witnesses) {
		if (n == a) return true; 
		ll p = fast_pow128(a, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = (i128)p * p % n;
		if (p != n - 1 && i != s) return false; 
	}
	return true;
}

/*** END MILLER-RABIN ***/

/*** BEGIN POLLARD RHO ***/

ll pollard(ll n) {
	auto f = [n](ll x) {
		return (fast_pow128(x, x, n) + 1) % n;
	};
	if (n % 2 == 0) return 2;

	for (ll i = 2; ; i++) {
		ll x = i, y = f(x), p;
		while ((p = gcd(n + y - x, n)) == 1)
			x = f(x), y = f(f(y));
		if (p != n) { return p; }
	}
}

void factorize /* O(nˆ(1/4)) */ (ll n) {
	if (n == 1) return;
	if (is_prime(n)) { cout << n << " "; return; }
	ll x = pollard(n);
	factorize(x); factorize(n/x);
}

/*** END POLLARD RHO ***/