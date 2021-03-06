class Solution {
public:
    const int MOD =1e9+7,MOD1=1e9+9;
    const int D = 257;
    string get(string &str,int len)
    {
        set<pair<int,int>> vec;
        long long int curr1 = 0,curr2=0;
        long long int off1 = 1,off2=1;
        for(int i=0;i<len-1;i++)
        {
            off1 = off1*D%MOD;
            off2 = off2*D%MOD1;
        }   
        for(int i=0;i<len ;i++)
        {
            curr1 = (curr1*D + str[i])%MOD;
            curr2 = (curr2*D + str[i])%MOD1;
        }    
        vec.insert({curr1,curr2});
        for(int i=0,j=len;j<str.size();i++,j++)
        {
            curr1 = (D*(curr1-off1*str[i]) + str[j])%MOD;
            curr2 = (D*(curr2-off2*str[i]) + str[j])%MOD1;
            if(curr1<0)
                curr1 += MOD;
            if(curr2<0)
                curr2 += MOD1;
            if(vec.find({curr1,curr2})!=vec.end())
                return str.substr(i+1,len);
            vec.insert({curr1,curr2});
        }
        return "";
    }
    string longestDupSubstring(string S)
    {
        int l = 0, r = S.size();
        while(l<r)
        {
            int m = l + (r-l+1)/2;
            if(get(S,m).size()!=0)
                l = m;
            else
                r = m - 1;
        }
        return get(S,l);
    }
};
