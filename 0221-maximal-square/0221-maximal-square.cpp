class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size() + 2);
        int before = 0;
        int maxn = 0;
        
        for (int i=1; i<=matrix.size(); i++)
        {
            for (int j=1; j<=matrix[i - 1].size(); j++)
            {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[j] = min(min(dp[j - 1], before), dp[j]) + 1;
                    maxn = max(maxn, dp[j]);
                }
                else
                {
                    dp[j] = 0;
                }
                before = temp;
            }
        }
        return maxn * maxn;
    }
};