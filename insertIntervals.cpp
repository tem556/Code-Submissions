class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int startNew {newInterval.at(0)};
        int endNew {newInterval.at(1)};
        vector<vector<int>>::iterator firstInterval {intervals.begin()};
        vector<vector<int>>::iterator lastInterval {intervals.end()};

        // if they're outside
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        else if (endNew < intervals.at(0).at(0)) {
            intervals.insert(firstInterval, newInterval);
            return intervals;
        } else if (intervals.at(intervals.size() - 1).at(1) < startNew) {
            intervals.push_back(newInterval);
            return intervals;
        }
        bool seen {false};
        bool left {true};

        vector<vector<int>>::iterator it {intervals.begin()};
        while (left && (it != intervals.end())) {
            vector<int> currInterval = *it;
            if (!seen && endNew < currInterval.at(0)) {
                intervals.insert(it, newInterval);
                return intervals;
            }
            if (!seen && (startNew <= currInterval.at(1))) {
                firstInterval = it;
                seen = true;
            }
            if (seen && endNew < currInterval.at(0)) {
                lastInterval = it;
                left = false;
            }
            it = next(it);
        }
        (*firstInterval).at(0) = min(startNew, (*firstInterval).at(0));
        (*firstInterval).at(1) = max(endNew, (*(lastInterval - 1)).at(1));
        intervals.erase(firstInterval + 1, lastInterval);


        return intervals;

    }
};
