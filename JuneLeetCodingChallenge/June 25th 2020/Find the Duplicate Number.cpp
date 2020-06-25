class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int m=nums[0];
        int i,n;
        for(i=0;i<nums.size();i++){
        if(m == nums[m])
        break; //if there already number is present then this is the duplicate one
        n = nums[m];
        nums[m]=m;
        m=n;
        }
        return m;
    }
};
