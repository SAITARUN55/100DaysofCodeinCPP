class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        map<int,int>m;
        priority_queue<pair<int,int>>j;
        
        
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        for(auto i:m)
            j.push({i.second,i.first});
        
        for(int i=1;i<=k;i++)
            {res.push_back(j.top().second);
            j.pop();
            }

        
        return res;
    }
};
