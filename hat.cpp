#include <bits/stdc++.h>


typedef long long ll;
#define int ll


//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//using ordered_set = tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;

void setmax (int &x, const int &y) { if (x < y) x = y; }

using namespace std;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;


#define endl "\n"
#define S second
#define F first
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define forn(i, n) for(int i = 0; i < ll(n); i++)
#define mp make_pair
#define pb push_back
#define sz(x) ll((x).size())

#define newln cout << endl;
#define yes "YES\n"
#define no "NO\n"

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    for (auto i: a) os << i << ' ';
    os << endl;
    return os;
}


/* ================== actual code =================== */


void solve() {
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }
}
