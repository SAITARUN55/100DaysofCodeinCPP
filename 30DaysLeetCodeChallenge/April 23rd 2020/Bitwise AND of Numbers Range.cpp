class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
         int count=0;
       // simple solution is to do bitwise and and return the sum. 
      //     for(int i=m;i<=n;i++)
      //               sum&=i;        
		 //      return sum;
        while(m!=n)  // see till both numbers are equal
        {   // right shift both numbers by 1
            m>>=1; 
            n>>=1;
            count++;  // increment the count.
        }
		//count gives the number of zero places from the lsb so left shift m by count.
        return m<<count;
    }
};
