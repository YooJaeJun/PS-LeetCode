class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ySize = matrix.size();
        int xSize = matrix[0].size();

        vector<int> height(xSize + 1);
        int ans = 0;

        for (int y = 0; y < ySize; y++)
        {
            stack<int> st;
            for (int x = 0; x <= xSize; x++)
            {
                if (x < xSize)
                {
                    height[x] = matrix[y][x] == '1' ? height[x] + 1 : 0;
                }

                while (!st.empty() && height[x] < height[st.top()])
                {
                    int h = height[st.top()];
                    st.pop();
                    int w = st.empty() ? x : x - 1 - st.top();
                    ans = max(ans, h * w);
                }
                st.push(x);
            }
        }

        return ans;
    }
};