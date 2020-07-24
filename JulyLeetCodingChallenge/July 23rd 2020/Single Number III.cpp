class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int totxor=0;
        
        for(int i = 0; i < nums.size(); i++)
            totxor ^= nums[i];

        int a=1;

        for(int i = 1; i < 32; i++)
        {
            if((totxor & a) == a)break; //check the occurence of the first set bit in the 'xor' value
            a <<= 1;
        }

        int first=0;
        int second=0;

        for(int i = 0; i < nums.size(); i++)
        {
            if((nums[i] & a) == a) first ^= nums[i];
            else second ^= nums[i];
        }

        return {first, second};
    }
};
