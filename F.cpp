#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define vb vector<bool>
#define pib pair<int, bool>

ll a, b, m;

struct matran {
    ll X[2][2];

    void ktao() {
        X[0][0] = X[0][1] = X[1][0] = 1;
        X[1][1] = 0;
    }

    friend matran operator * (matran a, matran b) {
        matran c;
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                c.X[i][j] = 0;
                for (int k=0; k<2; k++) {
                    c.X[i][j] += a.X[i][k] * b.X[k][j];
                    c.X[i][j] %= m;
                }
            }
        }

        return c;
    }
};

matran bPow(matran a, ll n) {
    if (n == 1) return a;
    matran tmp = bPow(a, n / 2);
    if (n & 1) {
        return tmp * tmp * a;
    } else {
        return tmp * tmp;
    }
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve()
{
    cin >> a >> b >> m;

    int n = gcd(a, b);
    matran res;
    res.ktao();
    res = bPow(res, n);
    cout << res.X[0][1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}