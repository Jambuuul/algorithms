//this algo is so easy there is actually no point in this, but i still added it

for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
}
