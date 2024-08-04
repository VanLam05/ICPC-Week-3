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
    vector<bool> prime (n + 5, true);
    prime[0] = prime[1] = false;

    int i = 2;
    while(i * i <= n) {
        int j = i * i;
        while(j <= n) {
            prime[j] = false;
            j += i;
        }
        i++;
        while(!prime[i]) i++;
    }

    int cnt = 0;
    for (int i=2; i<= n/2; i++) {
        cnt += (prime[i] && prime[n - i]);
    }
    cout << cnt;
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