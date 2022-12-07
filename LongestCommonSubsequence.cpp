class Solution {
public:
    unordered_map<int, int> map;
    string text1C;
    string text2C;
    int text1Len = 0;
    int text2Len = 0;

    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size();
        int j = text2.size();

        text1C = text1;
        text2C = text2;
        text1Len = i;
        text2Len = j;

        int memo[i * j];
        memset(memo, 0, i * j * sizeof(int));
        return longestHelper(i, j, memo);
    }

    int longestHelper(int i, int j, int memo[]) {
        if (i == 0 || j == 0) {
            return 0;
        }
        
        int old = memo[(j - 1) * text1Len + (i - 1)];
        // if already seen
        if (old != 0) 
            return old;

        if (text1C[i - 1] == text2C[j - 1]) {
            int finalRes = 1 + longestHelper(i - 1, j - 1, memo);
            memo[(j - 1) * text1Len + (i - 1)] = finalRes;
            return finalRes;
        } else {
            int res1 = longestHelper(i - 1, j, memo);
            int res2 = longestHelper(i, j - 1, memo);
            int finalRes = std::max(res1, res2);

            memo[(j - 1) * text1Len + (i - 1)] = finalRes;
            return finalRes;
        }

    }
};
