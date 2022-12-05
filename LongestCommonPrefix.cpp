#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest = strs[0];
        for (int i = 0; i < strs.size(); i++){
            if (strs[i].size() < longest.size())
                longest = strs[i];
        }
        for (int i = 0; i < strs.size(); i ++){
            for (int j = 0; j < longest.size(); j++)
                if (strs[i][j] != longest[j])
                    longest = longest.substr(0, j);
        }
    return longest;   
    }
};
