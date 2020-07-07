class Solution {
public:
    int islands = 0;
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
    private:
    void eraseIslands(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == 0) {
            islands++;
            return;
        }
        if(grid[i][j] == 2){
            return;
        }
        grid[i][j] = 2;
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};
