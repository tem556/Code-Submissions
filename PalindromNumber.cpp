#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        string s = std::to_string(x);
        int n = s.size();
        string y;

        for (int i = 0; i < n; i++){
            y.push_back(s[n - i - 1]);
        }

        for  (int i = 0; i < n; i++){
            if (s[i] != y[i])
                return false;
        }
        return true;
    }
};
