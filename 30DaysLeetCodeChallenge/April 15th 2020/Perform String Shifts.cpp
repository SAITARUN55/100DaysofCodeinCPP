class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        
        int val = 0;
        
        for(int i=0;i<shift.size();++i)
            val += shift[i][0]==0?-shift[i][1]:shift[i][1];
        
        int len = s.length();
        val %= len;
        
        string result = "";
        if(val>0)   //Right rotation
            result = s.substr(len-val,val) + s.substr(0,len-val);
        else        //Left rotation
            result = s.substr(-val,len+val) + s.substr(0,-val);
        
        return result;
    }
};
