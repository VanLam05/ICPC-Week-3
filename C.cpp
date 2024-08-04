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
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int num = q.front(); q.pop();
        if (num == n) {
            cout << "Yes";
            return;
        }

        if (num + 4 <= n) q.push(num + 4);
        if (num + 7 <= n) q.push(num + 7);
    }
    cout << "No";
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