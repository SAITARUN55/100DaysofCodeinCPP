class Solution {
public:
	bool isPowerOfTwo(int n) {
		// what does power of two look like: 1000000, one followed by trailing zeros
		// so if n is greater than 1, we keep checking whether  the last digit is 0
		// then erase last digit go to next loop
		// keep doing this until n less or equal to 1
		while(n>1)
		{
			if((n&1)==1) return false;
			n>>=1;
		}
		return n==1;

	}
};
