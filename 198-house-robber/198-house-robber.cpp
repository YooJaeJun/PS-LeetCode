class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size);
        dp[0] = nums[0];
        if (size > 1) { dp[1] = nums[1]; }

        for (int i = 2; i < size; i++) {
            for (int j = 2; i - j >= 0; j++) {
                dp[i] = max(dp[i], dp[i - j] + nums[i]);
            }
        }

        if (size > 1) {
            return max(dp[size - 1], dp[size - 2]);
        }
        else {
            return dp[0];
        }
    }
};