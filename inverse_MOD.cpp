ll bigmod(ll a, ll b, ll mod) {
    if (!b) return 1;

    ll x = bigmod(a, b / 2, mod);
    x = ((x % mod) * (x % mod)) % mod;

    if (b & 1) x = ((x % mod) * (a % mod)) % mod;
    return x;
}

ll inverse_mod(ll a, ll b) {
    ll ret = bigmod(b , MOD - 2 , MOD);
    ret = (ret * a) % MOD;
    return ret;
}
