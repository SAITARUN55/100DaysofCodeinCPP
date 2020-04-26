class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxRight = 0;
        for (int i = 0; i < n; i++){
            if (i > maxRight) return false;
            maxRight = max(i + nums[i], maxRight);            
        }
        return true;
    }
};
