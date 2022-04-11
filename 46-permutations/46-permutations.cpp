class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> visited;
    
    void bt(vector<int>& nums, vector<int>& v) {
        if(v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        for(int i=0;i!=nums.size();i++) {
            if(visited[i]) continue;
            visited[i] = true;
            v.push_back(nums[i]);
            bt(nums, v);
            v.pop_back();
            visited[i] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        visited.resize(nums.size());
        bt(nums, v);
        return ans;
    }
};