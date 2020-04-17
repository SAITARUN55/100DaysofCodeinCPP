class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size(),1);
        int pre=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            v[i]=pre;
            pre=pre*nums[i];
        }
        int post=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            v[i]=v[i]*post;
            post=post*nums[i];
        }
        return v;
    }
};
