class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result;
		//result.reserve(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
            {
                result.insert(result.begin(), A[i]);
            }
            else
            {
                result.insert(result.end(), A[i]);
            }
        }
        return result;
    }
};
