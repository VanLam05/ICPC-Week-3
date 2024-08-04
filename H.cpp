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
    vector<int> ind(n + 1);
    for (int i=1; i<=n; i++) {
        int p; cin >> p;
        ind[p] = i;
    }

    ll res = 0;
    set<int> s;
    s.insert(n + 1); s.insert(0);
    s.insert(ind[n]);
    for (int p=n-1; p>0; p--) {
        auto pos = s.insert(ind[p]).fi;

        auto nexPos1 = ++pos;
        auto nexPos2 = ++pos;
        int numNex = 0;
        if (nexPos2 != s.end()) 
            numNex = *nexPos2 - *nexPos1;
        pos--; pos--;

        auto prePos2 = --pos;
        int numPre = 0;
        if (prePos2 != s.begin()) {
            auto prePos1 = --pos;
            numPre = *prePos2 - *prePos1; 
            pos++;
        }
        pos++;

        res += (ll) p * numNex * (*pos - *prePos2);
        res += (ll) p * numPre * (*nexPos1 - *pos);
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