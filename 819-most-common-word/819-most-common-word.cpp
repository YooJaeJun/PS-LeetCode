class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(auto& elem : paragraph)
        {
            if (elem >= 'A' and elem <= 'Z') elem -= 'A' - 'a';
            else if (elem >= 'a' and elem <= 'z') {}
            else elem = ' ';
        }

        unordered_map<string, int> dic;
        for(auto& elem : banned)
            dic[elem] = -1;
        
        stringstream ss(paragraph);
        string str;
        while(ss >> str)
            if (dic[str] != -1) 
                dic[str]++;
        
        int maxn = 0;
        string ans;
        for(auto& elem : dic)
        {
            if (maxn < elem.second)
            {
                maxn = elem.second;
                ans = elem.first;
            }
        }
        
        return ans;
    }
};