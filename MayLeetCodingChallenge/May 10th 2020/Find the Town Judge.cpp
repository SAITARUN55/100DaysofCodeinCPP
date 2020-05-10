class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusts(N + 1, 0);
        for(auto person : trust){
            trusts[person[0]]--;
            trusts[person[1]]++;
        }
        for(int i = 1;i <= N;i++){
            if(trusts[i] == N - 1)
                return i;
        }
        return -1;
    }
};
