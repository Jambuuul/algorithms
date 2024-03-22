void calc_pref(vector<int>& a, int n, vector<int>& pref) {

    pref[0] = 0;

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i-1];
    }
}

void calc_diff(vector<int>& a, int n, vector<int>& diff) {

    //ведущий 0 уже добавлен

    for (int i = 0; i < n; i++) {
        diff[i] = a[i + 1] - a[i];
    }
}

void diff_query(int l, int r, int d, vector<int>& diff) {

    l--;

    diff[l] += d;

    if (r < diff.size()) {
        diff[r] -= d;
    }

}
