class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        multimap<int,int> m;
         for(int i=0; i<p.size();i++)
         m.insert({p[i][0]*p[i][0]+p[i][1]*p[i][1],i});
         vector<vector<int>>v;
         for(auto it=m.begin();k>0;it++,k--) 
         v.push_back(p[it->second]);
         return v;
    }
};
