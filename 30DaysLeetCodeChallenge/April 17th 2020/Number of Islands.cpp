class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
    if(m==0) return 0;
    int n = grid[0].size();
    if(n==0) return 0;    
    int no_of_islands = 0;    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(grid[i][j] == '1'){
                no_of_islands++;
                DFS(grid,i,j);
            }
        }
        return no_of_islands;
    }
    
    void DFS(vector<vector<char>>& grid,int i,int j){
        grid[i][j] = '0';
        if(i-1>=0 && grid[i-1][j]=='1')
            DFS(grid,i-1,j);
        if(j-1>=0 && grid[i][j-1]=='1')
            DFS(grid,i,j-1);
        if(i+1<grid.size() && grid[i+1][j]=='1')
            DFS(grid,i+1,j);
        if(j+1<grid[0].size() && grid[i][j+1]=='1')
            DFS(grid,i,j+1);
    }
};
