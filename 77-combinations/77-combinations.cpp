class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        function<void(vector<int>&, int)> comb = [&](vector<int>& cur, int idx)
        {
            if (cur.size() == k)
            {
                ans.push_back(cur);
                return;
            }
            for(int i = idx; i<=n; i++)
            {
                cur.push_back(i);
                comb(cur, i + 1);
                cur.pop_back();
            }
        };
        vector<int> cur;
        comb(cur, 1);
        return ans;
    }
};