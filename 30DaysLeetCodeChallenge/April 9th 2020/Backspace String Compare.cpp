class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string sf="",tf="";
        for(int i=0;i<S.length();i++){
            if(sf.empty()&& S[i]=='#')
                continue;
            
            if(S[i]=='#')
                sf.pop_back();
            
            else
                sf+=S[i];
        }
        for(int i=0;i<T.length();i++){
            if(tf.empty()&& T[i]=='#')
                continue;
            
            if(T[i]=='#')
                tf.pop_back();
            
            else
                tf+=T[i];
        }
        
        return sf==tf;
    }
};
