class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;


        int seen[127];
        memset(seen, 0, 127 * sizeof(int));

        int longest = 0;
        int curr = 0;

        for (int i = 0; i < s.length(); ++i)  {
            // check if you have seen already
            int charAscii = (int) s[i];
            if (seen[charAscii] && (seen[charAscii] - 1) >= (i - curr)) {
                // go back to last character that doesn't match
                curr = i - (seen[charAscii] - 1);
                seen[charAscii] = i + 1;
            } else {
                seen[charAscii] = i + 1; // fix issue with zero
                curr++;
                if (curr > longest) {
                    longest = curr;
                }
            }
        }
        
        return longest;
    }
};
