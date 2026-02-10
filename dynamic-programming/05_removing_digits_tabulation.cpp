#include <bits/stdc++.h>
using namespace std;

// loops
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define ROF(i,r,l) for (int i = (r); i >= (l); --i)

// shortcuts
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

// fast IO
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// types
using ll = long long;
using ull = unsigned long long;

// directions
const int dx4[4] = {0, 0, 1, -1};
const int dy4[4] = {1, -1, 0, 0};
const int dx8[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy8[8] = {1, -1, 0, 0, 1, -1, 1, -1};
const int INF = 1e9;

vector<int> get_digits(int x) {
    vector<int> res;
    while (x > 0) {
        int digit = x % 10;
        res.pb(digit);
        x = x / 10;
    }

    return res;
}

int solve(int x) {
    vector<int> steps(x+1, INF);
    steps[0] = 0;
    FOR(i, 1, x+1) {
        int num=i;
        while (num) {
            int d=num%10;
            num/=10;
            steps[i] = min(steps[i], steps[i-d]+1);
        }
    }
    return steps[x];
}

int main() {
    fastio;
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}
