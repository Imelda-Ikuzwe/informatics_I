/**
 Reminder: Use Recursion
 */

class Solution {
private:
    bool check(const string& s, int left, int right, int deletions) {
        if (left >= right) {
            return true;
        }
        if (s[left] == s[right]) {
            return check(s, left + 1, right - 1, deletions);
        }
        if (deletions > 0) {
            return check(s, left + 1, right, deletions - 1) || check(s, left, right - 1, deletions - 1);
        }
        return false;
    }

public:
    bool validPalindrome(string s) {
        return check(s, 0, s.length() - 1, 1);
    }
};
