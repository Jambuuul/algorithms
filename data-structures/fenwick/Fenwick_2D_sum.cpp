struct Fen2D {
    int n, m;
    vector<vector<int>> fen;

    void build(int n_, int m_) {
        n = n_;
        m = m_;
        fen.assign(n + 1, vector<int> (m + 1, 0));
    }

    void add(int val, int i, int j) {
        for (int i1 = i; i1 <= n; i1 += i1 & -i1) {
            for (int j1 = j; j1 <= m; j1 += j1 & -j1) {
                fen[i1][j1] += val;
            }
        }
    }

    int get(int i, int j) {
        int res = 0;
        for (int i1 = i; i1 > 0; i1 -= i1 & -i1) {
            for (int j1 = j; j1 > 0; j1-= j1 & -j1) {
                res += fen[i1][j1];
            }
        }
        return res;
    }
};
