class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int color, int newColor) {
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != color || image[row][col] == newColor)
            return;
        
        image[row][col] = newColor;
        dfs(image, row+1, col, color, newColor);
        dfs(image, row-1, col, color, newColor);
        dfs(image, row, col+1, color, newColor);
        dfs(image, row, col-1, color, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
