class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //Approach : Use queue to store the coordinates of rotten oranges 
        //Time Complexity : O(3*M*N) ~ O(M*N)
        //Space Complexity : O(M*N)
        queue< pair<int,int> > q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                    q.push(make_pair(i,j));
            }
        }
        int num_days = 0;
        while(!q.empty())
        {
            int k = q.size();
            while(k--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                //left
                if(y>0 && grid[x][y-1] == 1)
                {
                    grid[x][y-1] = 2;
                    q.push(make_pair(x,y-1));
                }
                //up
                if(x>0 && grid[x-1][y] == 1)
                {
                    grid[x-1][y] = 2;
                    q.push(make_pair(x-1,y));
                }
                //right
                if(y<m-1 && grid[x][y+1] == 1)
                {
                    grid[x][y+1] = 2;
                    q.push(make_pair(x,y+1));
                }
                //bottom
                if(x<n-1 && grid[x+1][y] == 1)
                {
                    grid[x+1][y] = 2;
                    q.push(make_pair(x+1,y));
                }
            }
            if(!q.empty())
                num_days++;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return num_days;
    }
};
