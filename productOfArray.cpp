class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int runningProd = 1;
        vector<int> right;
        for (auto &x : nums) {
            runningProd *= x;
            right.push_back(runningProd);
        }
        runningProd = nums[nums.size() - 1];
        nums[nums.size() - 1] = right[right.size() - 2];

        for (int i = nums.size() - 2; i >= 1; --i) {
            int x = nums.at(i);
            nums.at(i) = runningProd * right.at(i - 1);
            runningProd *= x;
        }
        nums[0] = runningProd;
        return nums;
    }
};
