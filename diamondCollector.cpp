#include<bits/stdc++.h> 
using namespace std; 

int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int n, k; 
    if (!(cin >> n >> k)) return 0;
    
    vector<int> a(n); 
    for(int i = 0; i < n; i++){ 
        cin >> a[i]; 
    } 
    
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    sort(a.begin(), a.end()); 
    
    vector<int> maxleft(n, 0); 
    
    int L = 0; 
    for (int R = 0; R < n; R++) { 
        while (a[R] - a[L] > k) { 
            L++; 
        } 
        int current_size = R - L + 1;
        if (R == 0) { 
            maxleft[R] = current_size; 
        } else { 
            maxleft[R] = max(maxleft[R - 1], current_size); 
        } 
    } 
    
    vector<int> maxright(n, 0);
    int R = n - 1;
    for (int L_ptr = n - 1; L_ptr >= 0; L_ptr--) {
        while (a[R] - a[L_ptr] > k) {
            R--;
        }
        int current_size = R - L_ptr + 1;
        if (L_ptr == n - 1) {
            maxright[L_ptr] = current_size;
        } else {
            maxright[L_ptr] = max(maxright[L_ptr + 1], current_size);
        }
    }
    
    int totaldiamonds = maxleft[n - 1]; 
    for (int i = 0; i < n - 1; i++) {
        totaldiamonds = max(totaldiamonds, maxleft[i] + maxright[i + 1]);
    }
    
    cout << totaldiamonds << "\n"; 
    return 0; 
}
