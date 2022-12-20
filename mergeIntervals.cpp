bool myFunc (vector<int> a, vector<int> b){
        return a.at(0) < b.at(0);
    }

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), myFunc);
        int startPtr = 0;
        int currMin = intervals.at(0).at(0);
        int currMax = intervals.at(0).at(1);
        vector<vector<int>> res;
        


        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> curr = intervals.at(i);
            int currStart = curr.at(0);
            int currEnd  = curr.at(1);

            if (currStart <= currMax) {
                currMin = min(currStart, currMin);
                currMax = max(currEnd, currMax);
            } else {
                vector<int> newInterval = {currMin, currMax};
                res.push_back(newInterval);
                startPtr = i;
                currMin = currStart;
                currMax = currEnd;
            }
        }
        vector<int> newInterval = {currMin, currMax};
        res.push_back(newInterval);

        return res;
    }
};
