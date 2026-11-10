#include <bits/stdc++.h>
using namespace std;

bool canPlace(long long D, int N, const vector<pair<long long, long long>>& intervals) {
    int count = 1;
    long long last_pos = intervals[0].first;
    int interval_idx = 0;
    int M = intervals.size();

    while (count < N && interval_idx < M) {
        long long next_min_pos = last_pos + D;

        while (interval_idx < M && intervals[interval_idx].second < next_min_pos) {
            interval_idx++;
        }

        if (interval_idx == M) {
            return false;
        }

        last_pos = max(intervals[interval_idx].first, next_min_pos);
        count++;
    }

    return count == N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<pair<long long, long long>> nums(M);
    for (int i = 0; i < M; i++) {
        cin >> nums[i].first >> nums[i].second;
    }

    sort(nums.begin(), nums.end());

    long long low = 1;
    long long high = (nums.back().second - nums[0].first) / (N - 1);
    long long ans = 1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canPlace(mid, N, nums)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
