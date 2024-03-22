struct FTree {
    int n;
    vector<int> fen;

    void build(vector<int>& a) {
        n = sz(a);
        fen.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            fen[i + 1] = fen[i] + a[i];
        }
        for (int i = n; i > 0; --i) {
            fen[i] -= fen[i - (i&-i)];
        }
    }

    void add(int x, int i) {
        for (;i <= n; i+= i & (-i)) {
            fen[i] += x;
        }

    }

    int get(int r) {
        int res = 0;
        for (; r > 0; r -= r & (-r)) {
            res += fen[r];
        }
        return res;
    }

    int sum(int l, int r) {
        return get(r) - get(l - 1);
    }
};
