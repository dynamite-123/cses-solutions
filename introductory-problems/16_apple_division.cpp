#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void foo(int idx, int n, ll sum, vector<int> &nums, vector<ll> &res) {
    if (idx >= n) {
        res.push_back(sum);
        return;
    }

    foo(idx + 1, n, sum + nums[idx], nums, res);
    foo(idx + 1, n, sum, nums, res);
}

int solve(int n, vector<int> &nums) {
    vector<ll> res;
    foo(0, n, 0, nums, res);

    ll s = 0;
    for (int i = 0; i < n; i++)
        s += nums[i];

    ll mn = INT_MAX;
    for (auto it : res) {
        if (it != s) {
            mn = min(abs(s - it - it), mn);
        }
    }

    return mn;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int res = solve(n, nums);
    cout << res << endl;

    return 0;
}
