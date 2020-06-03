class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N=costs.size(), n=N/2,ans= 0;
        vector<int>v(N);
        for (int i=0;i <N;i++) 
        {
            ans +=costs[i][0]+costs[i][1];
            v[i]=costs[i][0]-costs[i][1];
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < n; ++i)
            ans +=v[i];
        for (int i = n; i < N; ++i) 
            ans -=v[i];
        return ans/2;
    }
};
