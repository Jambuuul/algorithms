const int mod = 1e9 + 7;

const int MAXN = 1e6;


int binpow(int n, int p) {
    if (p == 0) return 1;

    if (n == 1) return 1;

    if (p % 2 == 0) {

        int tmp = binpow(n, p / 2) % mod;
        return (tmp * tmp) % mod;
    }
    return (binpow(n, p - 1) % mod * n) % mod;

}

int fact[MAXN + 1], ifact[MAXN + 1];

void f_fact() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
}

void f_ifact() {
    ifact[MAXN] = binpow(fact[MAXN], mod - 2);
    for (int i = MAXN - 1; i >= 0; i--) {
        ifact[i] = (i + 1) * ifact[i + 1] % mod;
    }
}

int C(int n, int k) {
    if (k < 0 || k > n || n < 0) return 0;

    return fact[n] * ifact[k] % mod * ifact[n - k] % mod;

}
