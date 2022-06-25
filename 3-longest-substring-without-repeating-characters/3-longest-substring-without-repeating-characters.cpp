class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        unordered_map<char, int> dic;
        int i = 0, j = 0;
        int ans = 0;

        while(1)
        {
            if (dic[s[j]] == 0) 
            {
                dic[s[j]]++;
                j++;
            }
            else
            {
                while(dic[s[j]] == 1)
                {
                    dic[s[i]]--;
                    i++;
                }
            }
            ans = max(ans, j - i);
            if (j >= s.size()) break;
        }
        return ans;
    }
};