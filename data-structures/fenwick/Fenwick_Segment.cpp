struct FenSeg {
    int n;
    vector<int> fen;

    void build(int n_) {
        n = n_;
        fen.assign(n + 1, 0);
    }
    void add_r(int val, int r) {
        for (; r > 0; r -= r& -r) {
            fen[r] += val;
        }
    }
    void add(int val, int l, int r) {
        add_r(val, r);
        add_r(-val, l - 1);
    }

    int get(int i) {
        int res = 0;
        for (; i <= n; i += i&-i) {
            res += fen[i];
        }
        return res;
    }
};
