class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++)
            res = (s[i] - 64) + res * 26 ; 
        return res;
    }
};
