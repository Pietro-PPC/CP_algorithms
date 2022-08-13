/*** BEGIN EXTGCD ***/

ll extgcd /* O(lg min(a, b)) */ (ll a, ll b, ll& x, ll& y) {
	if (b == 0) { x = 1; y = 0; return a; }
	ll g = extgcd(b, a%b, x, y);
	tie(x, y) = make_tuple(y, x - (a/b)*y);
	return g;
}

ll inv(ll a, ll m) {
	ll x, y; extgcd(a, m, x, y);
	return ((x % m) + m) % m;
}

/*** END EXTGCD ***/