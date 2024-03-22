    vector<int> pf(n);
    pf[0] = 0;
    for (int i = 1; i < n; i++) {
        int cur = pf[i - 1];
        while (cur > 0 && s[i] != s[cur]) {
            cur = pf[cur -1];
        }
        cur += s[i] == s[cur];
        pf[i] = cur;
    }
