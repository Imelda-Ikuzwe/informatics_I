#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    long long mid = n / 2;
    long long low = nums[mid];
    long long high = nums[mid] + k;
    long long ans = low;

    while (low <= high) {
        long long target = low + (high - low) / 2;
        long long ops = 0;

        for (int i = mid; i < n; i++) {
            if (nums[i] < target) {
                ops += target - nums[i];
            }
            if (ops > k) {
                break;
            }
        }

        if (ops <= k) {
            ans = target;
            low = target + 1;
        } else {
            high = target - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}

