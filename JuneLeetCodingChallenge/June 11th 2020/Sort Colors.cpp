class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for(int i = 0;i < nums.size(); i++){
            if(nums[i] == 2 && right!=i) swap(nums[i--], nums[right--]);
            else if(nums[i] == 0 && left!=i) swap(nums[i--], nums[left++]);
            if(i >= right) break;
        }
    }
};
