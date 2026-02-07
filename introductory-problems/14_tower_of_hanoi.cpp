#include <bits/stdc++.h>
using namespace std;

void toh(vector<pair<int, int>> &arr, int n, int s, int d, int t) {
    if (n == 0)
        return;

    toh(arr, n - 1, s, t, d);
    arr.push_back({s, d});
    toh(arr, n - 1, t, d, s);
}

void solve(int n) {
    vector<pair<int, int>> nums;
    toh(nums, n, 1, 3, 2);
    int N = nums.size();

    cout << N << endl;

    for (auto it : nums) {
        cout << it.first << " " << it.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;

    solve(n);

    return 0;
}
