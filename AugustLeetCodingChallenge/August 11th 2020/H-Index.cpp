class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Sorting it so that 
        sort(citations.begin(), citations.end(), greater<int>());
		// while going from left to right, H-index will increase and will be matched with the decreasing no. of citations for the paper
        for(int i = 0; i < citations.size(); i++)
		// the index at which H-index (i in this case) becomes >= to no. of citations at [i], it means the H - index cannot be greater than current i 
            if(i >= citations[i]) {
				// return i due to 0 - based indexing
                return i;
            }
		//  when smallest value citation is > the total no. of citations on the paper (i.e. its size)
        return citations.size();
    }
};
