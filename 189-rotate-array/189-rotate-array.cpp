class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	deque<int> dq;
        for (int i = 0; i != nums.size(); i++) {
            dq.push_back(nums[i]);
        }
        for (int i = 0; i != k; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        int size = dq.size();
        for (int i = 0; i != size; i++) {
            nums[i] = dq.front();
            dq.pop_front();
        }
    }
};