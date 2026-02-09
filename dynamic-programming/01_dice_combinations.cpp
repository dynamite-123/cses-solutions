#include <bits/stdc++.h>
using namespace std;

// loops
#define FOR(i, l, r) for (int i = (l); i < (r); ++i)
#define ROF(i, r, l) for (int i = (r); i >= (l); --i)

// shortcuts
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

// fast IO
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr)

// types
using ll = long long;
using ull = unsigned long long;

// directions
const int dx4[4] = {0, 0, 1, -1};
const int dy4[4] = {1, -1, 0, 0};
const int dx8[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy8[8] = {1, -1, 0, 0, 1, -1, 1, -1};

const ll MOD = 1e9 + 7;

ll foo(int s, vector<ll> &dp) {
    if (s < 0) {
        return 0;
    }
    if (s == 0) {
        return 1;
    }
    if (dp[s] != -1) {
        return dp[s];
    }
    ll cur = 0;
    FOR(i, 1, 7) { cur = (cur + foo(s - i, dp)) % MOD; }

    dp[s] = cur % MOD;
    return dp[s];
}

int main() {
    fastio;

    int n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    ll res = foo(n, dp);
    cout << res << endl;

    return 0;
}
