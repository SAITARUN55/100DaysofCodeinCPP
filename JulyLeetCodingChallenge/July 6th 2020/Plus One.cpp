class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;  // set i to last index
        while(i >=0 && digits[i] == 9){  // iterate till the number is not 9 or we reach the end of array
            digits[i] = 0;  // set that digit as 0
            i--; 
        }
        if(i == -1){   // if we reached end of array [9,9,9] create [1,0,0,0] and return
            vector<int>ans(digits.size()+1);  //size +1
            ans[0] = 1; //first value is 1
            return ans;
        }
        digits[i]++;   //  if all digits are not 9 then increment 1 to the index where i is pointing
        return digits;
    }
};
