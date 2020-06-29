class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n==1||m==1)
            return 1;
        vector<vector<int>> dp(2,vector<int>(m,1));
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i%2][j] = dp[(i-1)%2][j] + dp[i%2][j-1];
            }
        }
        return dp[(n-1)%2][m-1];
    }
};
