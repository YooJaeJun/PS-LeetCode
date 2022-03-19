class Solution {
public:
    string reverseWords(string s) {
        string s2, tmp;
        for(int i=0;i!=s.size();i++) {
            if(s[i] != ' ') {
                tmp += s[i];
            } else {
                for(int j=tmp.size()-1;j>=0;j--) {
                    s2 += tmp[j];
                }
                s2 += ' ';
                tmp.clear();
            }
        }
        
        for(int j=tmp.size()-1;j>=0;j--) {
            s2 += tmp[j];
        }
        
        return s2;
    }
};