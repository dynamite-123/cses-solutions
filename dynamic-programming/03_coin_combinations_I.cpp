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

ll solve(int x, int n, vector<int>& nums) {
    sort(all(nums));
    ll res = 0;
    vector<ll> dp(x+1, 0);
    dp[0] = 1;

    FOR(s, 0, x+1) {
        for(auto val : nums) {
            if (s-val>=0) {
                dp[s] = (dp[s] + dp[s-val]) % MOD;
            }
        }
    }
    return dp[x] % MOD;
}

int main() {
    fastio;
    int x, n;
    cin>>n>>x;

    vector<int> nums(n);
    FOR(i, 0, n) cin>>nums[i];
    ll res = solve(x, n, nums);
    cout<<res<<endl;
    return 0;
}
