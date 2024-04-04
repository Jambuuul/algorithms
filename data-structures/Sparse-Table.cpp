struct Sparse {
    int n;
    int LOG;
    vector<vector<int>> sparse;

    void build(vector<int> &a) {
        n = sz(a);
        LOG = __lg(n - 1) + 1;
        sparse.assign(LOG, vector<int>(n));

        sparse[0] = a;

        for (int i = 0; i < LOG - 1; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                sparse[i + 1][j] = min(sparse[i][j], sparse[i][j + (1 << (i))]);
            }
        }
    }

    int query(int l, int r) {
        l--;
        int pow = __lg(r - l);

        return min(sparse[pow][l], sparse[pow][r - (1 << pow)]);
    }
};
