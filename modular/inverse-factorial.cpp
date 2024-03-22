void f_ifact() {
    ifact[MAXN] = binpow(fact[MAXN], mod - 2);
    for (int i = MAXN - 1; i >= 0; i--) {
        ifact[i] = (i + 1) * ifact[i + 1] % mod;
    }
}
