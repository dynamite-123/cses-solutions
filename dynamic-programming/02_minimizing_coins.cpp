#include <bits/stdc++.h>
#include <unordered_map>
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
const int INF = 1e9;

int foo(int n, int s, vector<int> &nums, vector<int> &dp) {
    dp[0] = 0;

    FOR(i, 0, s + 1) {
        FOR(j, 0, n) {
            if (i - nums[j] >= 0 && dp[i - nums[j]] != INF)
                dp[i] = min(dp[i], dp[i - nums[j]] + 1);
        }
    }
    return dp[s];
}

int main() {
    fastio;
    int n, s;
    cin >> n >> s;
    vector<int> coins(n);
    FOR(i, 0, n) { cin >> coins[i]; }

    vector<int> dp(s + 1, INF);
    int res = foo(n, s, coins, dp);
    if (res >= INF) {
        cout << "-1\n";
    } else
        cout << res;

    return 0;
}
