class Solution {
public:
    bool detectCapitalUse(string word) {
        bool AllCap = true;
        bool AllSmall = true;
        bool ExpFirst = true;
        int n = word.size();

            if(islower(word[0])){
                ExpFirst = false;
            }
    
            for(int i = 0; i < n; i++){
        
                if(islower(word[i])){
                    AllCap = false;
                 }
        
                if(isupper(word[i])){
                    AllSmall = false;
                 }
        
        if(isupper(word[i])&&i!=0){
            ExpFirst = false;
        }
        
    }
    if(AllCap || AllSmall || ExpFirst){
        return true;
    }
    
    return false;
    }
};
