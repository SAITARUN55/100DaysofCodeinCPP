class Solution {
public:
    bool checkValidString(string s) {
        int bal = 0;
    for( int i=0; i < s.length(); i++ ) {
        if( s[i] == '(' || s[i] == '*' ) bal++;
        else bal--;
        if( bal < 0 ) return false;
    }
    if( bal == 0 ) return true;

    bal = 0;
    for( int i=s.length()-1; i >= 0; i-- ) {
        if( s[i] == ')' || s[i] == '*' ) bal++;
        else bal--;
        if( bal < 0 ) return false; 
     }
     return true;
    }
};
