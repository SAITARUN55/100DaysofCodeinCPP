class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> m; 
        for(char c : J)         m[c]++;
        for(char c : S)
          if(m.count(c)>0)      m['*']++;
        return m['*'];
    }
};
