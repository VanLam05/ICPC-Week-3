#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define vb vector<bool>
#define pib pair<int, bool>

const int INF = 1e9 + 5;

struct point{
    int x, y;

    void get() {
        cin >> x >> y;
    }
};

int dis(point A, point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<point> A(n + 1), B(m + 1);
    for (int i=1; i<=n; i++)
        A[i].get();
    for (int i=1; i<=m; i++) 
        B[i].get();

    vector<vector<pii>> dp(n + 1, vector<pii> (m + 1));
    dp[1][0] = {0, INF};
    for (int i=2; i<=n; i++) {
        dp[i][0].fi = dp[i-1][0].fi + dis(A[i], A[i-1]);
        dp[i][0].se = INF;
    } 

    dp[1][1] = {INF, dis(A[1], B[1])};
    for (int i=2; i<=m; i++) {
        dp[1][i].fi = INF;
        dp[1][i].se = dp[1][i-1].se + dis(B[i], B[i-1]);
    }

    for (int i=2; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j].fi = min(dp[i-1][j].fi + dis(A[i], A[i-1]), dp[i-1][j].se + dis(A[i], B[j]));
            dp[i][j].se = min(dp[i][j-1].fi + dis(B[j], A[i]), dp[i][j-1].se + dis(B[j], B[j-1]));
        }
    }

    cout << dp[n][m].fi;
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