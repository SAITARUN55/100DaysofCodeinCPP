class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int b = INT_MIN,s = 0,p_sell = 0,p_buy;
        for(int stock : prices){
            p_buy = b;
            b = max(b, p_sell - stock);
            p_sell = s;
            s = max(s, p_buy + stock);  
        }
        return s;
    }
};
