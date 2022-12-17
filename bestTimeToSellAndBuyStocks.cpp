class Solution {
public:
    int getMax(vector<int>& v) {
        int max = INT_MIN;

        for (auto &x : v) {
            if (x > max) {
                max = x;
            }
        }
        return max;
    }

    int maxProfit(vector<int>& prices) {
        int min = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < min) {
                int x = prices[i] - min;
                min = prices[i];
                prices[i] = x;
            } else {
                prices[i] = prices[i] - min;
            }
        }

        prices[0] = -1;
        return max(0, getMax(prices));
    }
    
};
