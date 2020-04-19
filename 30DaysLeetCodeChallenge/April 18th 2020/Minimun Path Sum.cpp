class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x = grid.size(); 
        if(x == 0) return 0;
        int y = grid[0].size();
        
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(i > 0 and j > 0) grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
                else if(i == 0 and j > 0) grid[i][j] += grid[i][j-1];
                else if(i > 0 and j == 0) grid[i][j] += grid[i-1][j];
            }
        }
        
        return grid[x-1][y-1];
    }
};
