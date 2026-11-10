#include <bits/stdc++.h>
using namespace std;

long long maxsubarraysum(int n, int a, int b, const vector<long long>& nums) {
    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        P[i + 1] = P[i] + nums[i];
    }

    long long maxsum = LLONG_MIN;
    deque<int> sumtracker;

    for (int i = a; i <= n; ++i) {
        while (!sumtracker.empty() && P[sumtracker.back()] >= P[i - a]) {
            sumtracker.pop_back();
        }
        sumtracker.push_back(i - a);

        while (!sumtracker.empty() && sumtracker.front() < i - b) {
            sumtracker.pop_front();
        }
        maxsum = max(maxsum, P[i] - P[sumtracker.front()]);
    }
    return maxsum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    if (cin >> n >> a >> b) {
        vector<long long> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << maxsubarraysum(n, a, b, nums) << "\n";
    }
    return 0;
}
