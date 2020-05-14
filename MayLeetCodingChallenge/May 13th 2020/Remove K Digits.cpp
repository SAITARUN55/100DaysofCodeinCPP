class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";
		// If a digit is greater than next one, delete it.
        for(auto& s:num){
            while(k>0 && !res.empty() && res.back()>s){
                res.pop_back();
                k--;
            }
			// Strip all leading '0'
            if(res.empty() && s=='0')
                 continue;
            res.push_back(s);
        }
        if(res.empty())
            return "0";
		// If all digits are increasingly sorted, delete last.
        res.resize(res.size()-k);
        if(res.empty())
            return "0";
        else return res;
    }
};
