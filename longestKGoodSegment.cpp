#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (int a = 0; a < n; a++) {
        cin >> nums[a];
    }

    unordered_map<long long, long long> count;
    long long left = 0;
    long long uniqueItems = 0;
    long long bestStart = 0;
    long long bestEnd = -1;

    for (int right = 0; right < nums.size(); right++) {
        long long current = nums[right];
        if (count[current] == 0) {
            uniqueItems++;
        }
        count[current]++;

        while (uniqueItems > k) {
            long long leftItem = nums[left];
            count[leftItem]--;
            if (count[leftItem] == 0) {
                uniqueItems--;
            }
            left++;
        }

        long long currentLen = right - left + 1;
        long long bestLen = bestEnd - bestStart + 1;
        if (currentLen > bestLen) {
            bestStart = left;
            bestEnd = right;
        }
    }

    cout << bestStart+1 <<" "<<bestEnd+1<< '\n';
 

    return 0;
}
