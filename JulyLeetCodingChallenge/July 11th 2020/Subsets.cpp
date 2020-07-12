class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        vector<int> tmp;
        int len;
        for (int n: nums) {
            len = res.size();
            for (int i = 0; i < len; i++) {
                tmp = res[i];
                tmp.push_back(n);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
