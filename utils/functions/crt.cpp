/*** BEGIN CRT ***/
// ALSO IMPORT EXTGCD

ll crt /* O(t lg m1*..*mt) */ (vll a, vll m, int t) {
	ll p = 1; for (ll& mi : m) { p *= mi; }
	ll ans = 0;
	for (int i = 0; i < t; i++) {
		ll pp = p / m[i];
		ans = (ans + ((a[i] * inv(pp, m[i])) % p * pp) % p) % p;
	}
	return ans;
}

/*** END CRT ***/