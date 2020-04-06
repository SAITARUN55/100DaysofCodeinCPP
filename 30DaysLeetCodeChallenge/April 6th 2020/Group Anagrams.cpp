class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            string x=strs[i];
            sort(x.begin(),x.end());
            m[x].push_back(strs[i]);
        }
        map<string,vector<string>> :: iterator it;
        for(it=m.begin();it!=m.end();it++)
            v.push_back(it->second);
        return v;
    }
};
