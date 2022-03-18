class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		stable_sort(nums.begin(), nums.end(), comp);
	}
	struct {
		bool operator()(const int& n1, const int& n2) {
			return n2 == 0 ? 1 : 0;
		}
	} comp;
};