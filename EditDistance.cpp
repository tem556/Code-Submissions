using namespace std;

class Solution {
public:
    unordered_map<int, int> map;

    int minDistance(string word1, string word2) {
        int i = word1.size();
        int j = word2.size();

        // if already seen
        if (map[(i << 16)  | j] != 0) 
            return map[(i << 16)  | j];

        if (i == 0) 
            return j;
        if (j == 0)
            return i;

        string subWord1 = word1.substr(0, i - 1);
        string subWord2 = word2.substr(0, j - 1);

        if (word1.back() == word2.back()) {
            int finalRes = minDistance(subWord1, subWord2);
            map[(i << 16)  | j] = finalRes;
            return finalRes;
        } else {
            int res1 = 1 + minDistance(subWord1, word2);
            int res2 = 1 + minDistance(word1, subWord2);
            int res3 = 1 + minDistance(subWord1, subWord2);
            int finalRes = std::min(res1, res2);
            finalRes = std::min(finalRes, res3);

            map[(i << 16)  | j] = finalRes;
            return finalRes;
        }
    }
};
