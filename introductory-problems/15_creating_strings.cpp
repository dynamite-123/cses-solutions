#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void next_permutation(vector<char> &nums) {
    int N = nums.size();
    if (N < 2)
        return;

    int bp = -1;

    for (int i = N - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            bp = i - 1;
            break;
        }
    }

    if (bp == -1) {
        sort(nums.begin(), nums.end());
        return;
    }

    for (int i = N - 1; i > bp; i--) {
        if (nums[bp] < nums[i]) {
            swap(nums[bp], nums[i]);
            break;
        }
    }
    sort(nums.begin() + bp + 1, nums.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<char> ans;
    string s;
    cin >> s;

    for (char c : s)
        ans.push_back(c);

    long long fact = 1;
    for (int i = 2; i <= s.size(); i++)
        fact *= i;

    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;

    for (auto [_, f] : freq) {
        long long d = 1;
        for (int i = 2; i <= f; i++)
            d *= i;
        fact /= d;
    }

    cout << fact << "\n"; // 20

    sort(ans.begin(), ans.end());

    vector<char> start = ans;

    do {
        for (char c : ans)
            cout << c;
        cout << "\n";
        next_permutation(ans);
    } while (ans != start);

    return 0;
}
