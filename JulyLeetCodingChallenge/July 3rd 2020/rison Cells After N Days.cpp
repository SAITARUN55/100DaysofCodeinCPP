class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) 
    {
        vector<int> Ans(8, 0);
        vector<vector<int> > lookup;
        
        while(N--)
        {
            for(int j=1; j<7; ++j)
            {
                if(cells[j-1] ^ cells[j+1]) Ans[j] = 0;     //both are different ie (1,0) or (0,1) using XOR
                else Ans[j] = 1;
            }
            
            if(lookup.size() && lookup.front() == Ans)      //found in the lookup table (ie cycle has begun)
            {
                return lookup[N % lookup.size()];
            }
            else lookup.push_back(Ans);                     //not found in the lookup (ie no cycle yet)
            
            cells = Ans;                                    //update cells
        }
        
        return cells;
    }
};

