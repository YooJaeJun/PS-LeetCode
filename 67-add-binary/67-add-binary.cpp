class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a, b);    // a>b
        int diff = a.size() - b.size();
        int carry = 0;
        string ans;
        for(int i=a.size()-1; i>=0; i--)
        {
            int sum = carry + a[i] - '0';
            carry = 0;
            if (i - diff >= 0) sum += b[i - diff] - '0';
            if (sum >= 2) carry = 1;
            sum %= 2;
            ans = to_string(sum) + ans;
        }
        if (carry == 1) ans = '1' + ans;
        
        return ans;
    }
};