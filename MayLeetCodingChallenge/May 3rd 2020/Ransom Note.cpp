class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
        for (char ch: magazine) dict[ch]++;
        for (char ch: ransomNote){
            if (dict[ch]) dict[ch]--;
            else return false;
        }
        return true;
    }
};
