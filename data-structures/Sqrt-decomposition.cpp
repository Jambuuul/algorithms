  int len = sqrt(n + .0) + 1;
  vector<int> dcmp(len);
  for (int i = 0; i < n; i++) {
      dcmp[i / len] = max(dcmp[i / len], a[i]);
  }

  int q;
  cin >> q;
  while (q --> 0) {
      int l, r;
      cin >> l >>r;
      l--;r--;
      int res = INT_MIN;
      int c_l = l / len, c_r = r / len;

      if (c_l == c_r) {
          for (int i = l; i <= r; i++) {
              res = max(res, a[i]);
          }
      } else {
          for (int i = l, end = (c_l + 1) * len - 1; i <= end; i++) {
              res = max(a[i], res);
          }
          for (int i = c_l + 1; i <= c_r - 1; i++) {
              res = max(res, dcmp[i]);
          }
          for (int i = c_r * len; i <= r; i++) {
              res = max(a[i], res);
          }
      }
      cout << res << ' ';
  }
