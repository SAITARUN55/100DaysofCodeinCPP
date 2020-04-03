class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int cur = maxSum;
        for (int i = 1; i < nums.size(); i++) {
            if (cur + nums[i] > nums[i]) {
                cur += nums[i];
            }
            else {
                cur = nums[i];
            }
            maxSum = max(maxSum, cur);
        }
        return maxSum; 
    }
};
