class Solution {
public:
	bool isPalindrome(int x) {
		string s = to_string(x);
		bool isValid = true;
		for (int i = 0; i != s.size(); i++) {
			if (s[i] != s[s.size() - 1 - i]) {
				isValid = false;
				break;
			}
		}
		return isValid;
	}
};