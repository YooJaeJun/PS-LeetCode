class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for(int i=0;i!=size / 2;i++) {
            char tmp = s[i];
            s[i] = s[size - 1 - i];
            s[size - 1 - i] = tmp;
        }
    }
};