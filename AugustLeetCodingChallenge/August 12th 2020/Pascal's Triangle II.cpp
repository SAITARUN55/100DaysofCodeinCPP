class Solution {
public:
vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 0);
        ans[0] = 1;
        for(int index=1; index<rowIndex+1; index++)
            for(int j=index; j>=1; j--)
                ans[j] += ans[j-1];
        return ans;
    }
    };
