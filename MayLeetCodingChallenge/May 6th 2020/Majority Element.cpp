class Solution {
public:
    int majorityElement(vector<int>& nums) {
  // Based on Moore's Voting Algorithm
	// which gets you majority element if it exists
	int majority = nums[0], vote=1;
	for( auto num : nums ) {
		if( num == majority )
			vote++;
		else if( --vote == 0 ) {
			majority = num;
			vote = 1;
		}
	}
	return  majority; 
    }
};
