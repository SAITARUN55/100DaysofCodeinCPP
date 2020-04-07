class Solution {
public:
    int countElements(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(arr[j]==arr[i]+1)
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
