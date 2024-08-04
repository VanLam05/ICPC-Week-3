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
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    ll res = 0;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        sum = (sum + a) % k;
        res += (ll) mp[sum]++;
    }

    cout << res;
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}