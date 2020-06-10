class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = 0;
        while (idx < nums.size() && nums[idx] < target)
            idx++;
        return idx;
    }
};
