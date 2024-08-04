#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define vb vector<bool>
#define pib pair<int, bool>

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int> f(n, 0);
    int m = 0;
    int curMax = 0;
    for (int i=0; i<n; i++) {
        if (a[i] > curMax) {
            f[i]++;
            curMax = a[i];
        }
    }

    int curMin = 1e6 + 5;
    for (int i=n-1; i>=0; i--) {
        if (a[i] < curMin) {
            f[i]++;
            curMin = a[i];
            if (f[i] == 2) m++;
        }
    }
    cout << m << ' ';
    m = min(m, 100);
    int i = 0;
    while(m) {
        if (f[i] == 2) {
            cout << a[i] << ' ';
            m--;
        }
        i++;
    }
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
   // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}