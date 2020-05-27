class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        int max_len = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i] == 1 ? 1 : -1;
            if (count == 0) {
                // if the count is 0, the maximum
                // will always be i + 1
                max_len = i + 1;
            } else if (freq.find(count) != freq.end()) {
                // if we already encountered the current count
                // the length between the first encounter and i
                // is a contiguous array of equal count
                max_len = max(max_len, i - freq[count]);
            } else {
                // if we haven't seen this count before
                // add it to the frequncy map
                freq[count] = i;
            }
        }
        
        return max_len;
    }
};
