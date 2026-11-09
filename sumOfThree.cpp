#include <bits/stdc++.h>
using namespace std;

int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;



    vector<pair<int, int>> nums;
    for (int a = 0; a < n; a++) {
        int t;
        cin >> t;
        nums.push_back({t, a + 1});
    }

 
    sort(nums.begin(), nums.end());

    bool found = false;
    
    for (int i = 0; i < n - 2; i++) {
        int low = i + 1;
        int high = n - 1;

        while (low < high) {
            int currentsum = nums[i].first + nums[low].first + nums[high].first;

            if (currentsum == x) {
           
                cout << nums[i].second << " " << nums[low].second << " " << nums[high].second << "\n";
                found = true;
                break;
            } 
            else if (currentsum < x) {
                low++;
            } 
            else {
                high--;
            }
        }
        if (found) {
            break;
        }
    }

    
    if (!found) {
        cout << "IMPOSSIBLE"<<'\n';
    }

    return 0;
}
